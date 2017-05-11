/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:50 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:51 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_mfd	*gnl_find_mfd(const size_t fd, t_mfd **begin)
{
	t_mfd	*mfd;

	mfd = *begin;
	while (mfd && mfd->content_size != fd)
		mfd = mfd->next;
	return (mfd);
}

static char		*gnl_make_line(int fd, t_mfd **begin)
{
	t_mfd		*mfd;
	char		*str;
	char		*end;
	char		*ptr;

	mfd = gnl_find_mfd(fd, begin);
	if (!mfd->content)
		return (NULL);
	if ((end = ft_strchr(mfd->content, '\n')))
	{
		*end = '\0';
		if (!(str = ft_strdup(mfd->content)))
			return (NULL);
		ptr = mfd->content;
		mfd->content = (ft_strlen(end + 1) == 0) ? NULL : ft_strdup(end + 1);
		free(ptr);
	}
	else
	{
		if (!(str = ft_strdup(mfd->content)))
			return (NULL);
		free(mfd->content);
		mfd->content = NULL;
	}
	return (str);
}

static int		gnl_make_mfd(int fd, char *buff, t_mfd **begin)
{
	t_mfd		*mfd;
	char		*ptr;

	mfd = gnl_find_mfd((size_t)fd, begin);
	if (!mfd)
	{
		if (!(mfd = (t_mfd *)ft_lstnew((void*)buff, (ft_strlen(buff) + 1))))
			return (-1);
		mfd->content_size = (size_t)fd;
		ft_lst_push_back((t_list**)begin, (t_list*)mfd);
	}
	else
	{
		if (!(ptr = ft_strjoin(mfd->content, buff)))
			return (-1);
		free(mfd->content);
		mfd->content = ptr;
	}
	if (ft_strchr(mfd->content, '\n'))
		return (1);
	return (0);
}

static char		*gnl_check_buff(int fd, t_mfd **begin)
{
	t_mfd		*mfd;

	mfd = gnl_find_mfd(fd, begin);
	if (mfd)
	{
		if (mfd->content)
			if (ft_strchr(mfd->content, '\n'))
				return (gnl_make_line(fd, begin));
		return (NULL);
	}
	else
		return (NULL);
}

int				_get_next_line(int fd, char **line)
{
	static t_mfd	*begin;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if ((*line = gnl_check_buff(fd, &begin)))
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (-1);
		buff[ret] = '\0';
		if ((ret = gnl_make_mfd(fd, buff, &begin)) > 0)
		{
			*line = gnl_make_line(fd, &begin);
			return (1);
		}
		if (ret < 0)
			return (-1);
	}
	if ((*line = gnl_make_line(fd, &begin)))
		return (1);
	return (0);
}

void			fill_drop_edge(t_fill *fill)
{
	fill->w[0] = fill->height - 1;
	fill->w[1] = fill->width - 1;
	fill->n[0] = fill->height - 1;
	fill->n[1] = fill->width - 1;
	fill->e[0] = 0;
	fill->e[1] = 0;
	fill->s[0] = 0;
	fill->s[1] = 0;
	fill->enemy->w[0] = fill->height - 1;
	fill->enemy->w[1] = fill->width - 1;
	fill->enemy->n[0] = fill->height - 1;
	fill->enemy->n[1] = fill->width - 1;
	fill->enemy->e[0] = 0;
	fill->enemy->e[1] = 0;
	fill->enemy->s[0] = 0;
	fill->enemy->s[1] = 0;
	fill->piece->w[0] = fill->piece->height - 1;
	fill->piece->w[1] = fill->piece->width - 1;
	fill->piece->n[0] = fill->piece->height - 1;
	fill->piece->n[1] = fill->piece->width - 1;
	fill->piece->e[0] = 0;
	fill->piece->e[1] = 0;
	fill->piece->s[0] = 0;
	fill->piece->s[1] = 0;
}

static void	fill_map_init(t_fill *fill)
{
	size_t	i;

	i = 0;
	fill->map = (char**)malloc(sizeof(char*) * fill->height);
	while (i < fill->height)
	{
		fill->map[i] = (char*)malloc(fill->width);
		i++;
	}
	fill->c[0] = fill->height / 2;
	fill->c[1] = fill->width / 2;
}

int			main()
{
	t_fill	fill;

	fill.enemy = (t_enemy*)malloc(sizeof(t_enemy));
	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}
