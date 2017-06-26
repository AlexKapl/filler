/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:20 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 18:00:13 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_tabdelz(char ***tab, int count)
{
	int		i;

	i = 0;
	return;
	if (count < 0)
		while ((*tab)[i])
		{
//			ft_printf("|%s|\n", *(*(tab) + i));
			free((*tab)[i]);
//			ft_printf("freed\n");
			i++;
		}
	else
		while (i < count)
		{
			free((*tab)[i]);
			i++;
		}
	free(*tab);
	*tab = NULL;
}

static int		gnl_make_line(char **buffer, char **line)
{
	char		*end;
	char		*tmp;

	if ((end = ft_strchr(*buffer, '\n')))
	{
		*end = '\0';
		*line = ft_strdup(*buffer);
		tmp = *buffer;
		if (*(end + 1))
			*buffer = ft_strdup(end + 1);
		else
			*buffer = ft_strnew(0);
		free(tmp);
		return (1);
	}
	else if (**buffer)
	{
		*line = ft_strdup(*buffer);
		tmp = *buffer;
		*buffer = ft_strnew(0);
		free(tmp);
		return (1);
	}
	return (0);
}

int				gnl(int const fd, char **line)
{
	static char	*buffer = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	if (!buffer)
		buffer = ft_strnew(0);
	while (!(ft_strchr(buffer, '\n')))
	{
		if ((ret = read(fd, buff, BUFF_SIZE)) < 0)
			return (-1);
		if (!ret)
			return (gnl_make_line(&buffer, line));
		buff[ret] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (gnl_make_line(&buffer, line));
}

void		fill_get_info(t_fill *fill)
{
	char	*buff;
	char	*tmp;
	char	**tab;

	buff = NULL;
	gnl(fill->fd, &buff);
//	ft_printf("{fd}%s\n", fill->fd1, buff);
	tmp = ft_strchr(buff, 'p');
	fill->fig = (char)(*(tmp + 1) == '2' ? 'X' : 'O');
	ft_strdel(&buff);
	gnl(fill->fd, &buff);
//	ft_printf("{fd}%s\n", fill->fd1, buff);
	tab = ft_strsplit(buff, ' ');
	fill->height = ft_atoi(tab[1]);
	fill->width = ft_atoi(tab[2]);
	fill->c[0] = fill->height / 2;
	fill->c[1] = fill->width / 2;
	ft_tabdelz(&tab, -1);
	ft_strdel(&buff);
}

static void	fill_read_piece(t_fill *fill)
{
	char	*buff;
	char	**tmp;
	int		i;

	i = 0;
	buff = NULL;
	gnl(fill->fd, &buff);
//	ft_printf("{fd}%s\n", fill->fd1, buff);
	tmp = ft_strsplit(buff, ' ');
	fill->p->height = ft_atoi(tmp[1]);
	fill->p->width = ft_atoi(tmp[2]);
	ft_strdel(&buff);
	ft_tabdelz(&tmp, -1);
	if (fill->p->place)
		ft_tabdelz(&fill->p->place, -1);
	if (!(fill->p->place = (char**)malloc(sizeof(char*) * (fill->p->height + 1))))
		exit(0);
	while (i < fill->p->height)
	{
		gnl(fill->fd, &buff);
		fill->p->place[i] = ft_strdup(buff);
//		ft_printf("{fd}%s\n", fill->fd1, buff);
		ft_printf("{fd}%s\n", fill->fd1, fill->p->place[i]);
		ft_strdel(&buff);
		i++;
	}
	fill->p->place[i] = NULL;
}

static t_fill	*fill_read_map(t_fill *fill)
{
	int		i;
	char	*buff;

	i = 0;
	buff = NULL;
	if (fill->map)
		ft_tabdelz(&fill->map, -1);
	if (!(fill->map = (char**)malloc(sizeof(char*) * (fill->height + 1))))
		exit(0);
	while (i < fill->height)
	{
		gnl(fill->fd, &buff);
		fill->map[i] = ft_strdup(buff + 4);
//		ft_printf("{fd}%s\n", fill->fd1, buff);
		ft_printf("{fd}|%s|%d\n", fill->fd1, fill->map[i], i);
		ft_strdel(&buff);
		i++;
	}
	fill->map[i] = NULL;
	return (fill);
}

void		fill_reader(t_fill *fill)
{
	char	*buff;
	int		i;

	while (gnl(fill->fd, &buff) > 0)
	{
//		ft_printf("{fd}%s\n", fill->fd1, buff);
		if (*buff == ' ')
		{
			fill = fill_read_map(fill);
			i = 0;
			while (i < fill->height)
			{
				ft_printf("{fd}|%s|%d\n", fill->fd1, fill->map[i], i);
				i++;
			}
			fill_read_piece(fill);
			fill_check_map(fill);
			fill_place_piece(fill);
		}
		ft_strdel(&buff);
	}
}
