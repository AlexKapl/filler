/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:20 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:22 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_get_info(t_fill *fill)
{
	char	*buff;
	char	*tmp;
	char	**tab;

	buff = NULL;
	get_line_by_line(0, &buff);
	tmp = ft_strchr(buff, 'p');
	fill->fig = (char)(*(tmp + 1) == '2' ? 'X' : 'O');
	free(buff);
	get_line_by_line(0, &buff);
	tab = ft_strsplit(buff, ' ');
	fill->height = (size_t)ft_atoi(tab[1]);
	fill->width = (size_t)ft_atoi(tab[2]);
	ft_tabdel(tab, -1);
	free(buff);
}

static void	fill_read_piece(t_fill *fill, char *data)
{
	char	*buff;
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = ft_strsplit(data, ' ');
	fill->p->height = (size_t)ft_atoi(tmp[1]);
	fill->p->width = (size_t)ft_atoi(tmp[2]);
	ft_tabdel(tmp, -1);
	fill->p->place = (char**)malloc(sizeof(char*) * fill->p->height);
	while (i < fill->p->height)
	{
		get_line_by_line(0, &buff);
		fill->p->place[i] = ft_strdup(buff);
//		ft_printf("|%s|\n", fill->p->place[i]);
		free(buff);
		i++;
	}
}

static void	fill_read_map(t_fill *fill)
{
	size_t	i;
	char	*buff;

	i = 0;
	fill->map = (char**)malloc(sizeof(char*) * fill->height);
	while (i < fill->height)
	{
		get_line_by_line(0, &buff);
		fill->map[i] = ft_strdup(buff + 4);
//		ft_printf("|%s|\n", fill->map[i]);
		free(buff);
		i++;
	}
}

void		fill_reader(t_fill *fill)
{
	char	*buff;

	while (get_line_by_line(0, &buff) > 0)
	{
		if (*buff == ' ')
			fill_read_map(fill);
		else if (ft_strstr(buff, "Piece"))
		{
			fill_read_piece(fill, buff);
			fill_drop_pos(fill);
			fill_check_map(fill);
			fill_place_piece(fill);
			fill_free_data(fill);
		}
		free(buff);
	}
}
