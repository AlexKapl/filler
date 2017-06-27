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

static void	fill_clean(t_fill *fill)
{
	if (fill->map)
		ft_tabdel(&fill->map, -1);
	if (fill->p->place)
		ft_tabdel(&fill->p->place, -1);
}

void		fill_get_info(t_fill *fill)
{
	char	*buff;
	char	*tmp;
	char	**tab;

	buff = NULL;
	get_next_line(0, &buff);
	tmp = ft_strchr(buff, 'p');
	fill->fig = (char)(*(tmp + 1) == '2' ? 'X' : 'O');
	ft_strdel(&buff);
	get_next_line(0, &buff);
	tab = ft_strsplit(buff, ' ');
	fill->height = ft_atoi(tab[1]);
	fill->width = ft_atoi(tab[2]);
	fill->c[0] = fill->height / 2;
	fill->c[1] = fill->width / 2;
	ft_tabdel(&tab, -1);
	ft_strdel(&buff);
}

static void	fill_read_piece(t_fill *fill)
{
	char	*buff;
	char	**tmp;
	int		i;

	i = 0;
	buff = NULL;
	get_next_line(0, &buff);
	tmp = ft_strsplit(buff, ' ');
	fill->p->height = ft_atoi(tmp[1]);
	fill->p->width = ft_atoi(tmp[2]);
	ft_strdel(&buff);
	ft_tabdel(&tmp, -1);
	fill->p->place = (char**)malloc(sizeof(char*) * (fill->p->height + 1));
	while (i < fill->p->height)
	{
		get_next_line(0, &buff);
		fill->p->place[i] = ft_strdup(buff);
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
	fill->map = (char**)malloc(sizeof(char*) * (fill->height + 1));
	while (i < fill->height)
	{
		get_next_line(0, &buff);
		fill->map[i] = ft_strdup(buff + 4);
		ft_strdel(&buff);
		i++;
	}
	fill->map[i] = NULL;
	return (fill);
}

void		fill_reader(t_fill *fill)
{
	char	*buff;

	while (get_next_line(0, &buff) > 0)
	{
		if (*buff == ' ')
		{
			fill = fill_read_map(fill);
			fill_read_piece(fill);
			fill_check_map(fill);
			fill_place_piece(fill);
			fill_clean(fill);
		}
		ft_strdel(&buff);
	}
}
