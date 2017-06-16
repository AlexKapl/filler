/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:16 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:16 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_save_out(t_fill *fill, size_t i, size_t j)
{
	fill->out[0] = i;
	fill->out[1] = j;
	fill->out_count++;
}

static void	fill_apply_strategy(t_fill *fill, size_t i, size_t j, size_t way)
{
	int		ss;
	int		gg;

	if (way == 2)
	{
		ss = ft_abs(((int)fill->out[0] - (int)fill->pos[0]) +
					((int)fill->out[1] - (int)fill->pos[1]));
		gg = ft_abs(((int)fill->pos[0] - (int)i) + ((int)fill->pos[1] - (int)j));
		if (gg > ss)
			fill_save_out(fill, i, j);
	}
	else
	{
		ss = ft_abs(((int)fill->out[0] - (int)fill->edge[0]) +
					((int)fill->out[1] - (int)fill->pos[1]));
		gg = ft_abs(((int)fill->edge[0] - (int)i) + ((int)fill->pos[1] - (int)j));
		if (gg < ss)
			fill_save_out(fill, i, j);
	}
}

static int	fill_check_strategy(t_fill *fill, size_t i, size_t j)
{
	size_t	way_out;
	char	**m;
	int		ss;
	int		gg;

	m = fill->map;
	if (m[fill->pos[0]][fill->edge[1]] == '.')
	{
		way_out = 0;
		ss = ft_abs(((int)fill->out[0] - (int)fill->pos[0]) +
					((int)fill->out[1] - (int)fill->edge[1]));
		gg = ft_abs(((int)fill->pos[0] - (int)i) + ((int)fill->edge[1] - (int)j));
		if (gg < ss)
			fill_save_out(fill, i, j);
	}
	else if (m[fill->edge[0]][fill->pos[1]] == '.')
		way_out = 1;
	else
		way_out = 2;
	if (way_out)
		fill_apply_strategy(fill, i, j, way_out);
	return (0);
}

static int	fill_check_place(t_fill *fill, size_t i, size_t j)
{
	size_t	y;
	size_t	x;

	y = 0;
	fill->x = 0;
	while (y < fill->p->height)
	{
		x = 0;
		while (x < fill->p->width)
		{
			if (fill->map[i + y][j + x] != '.' && fill->p->place[y][x] != '.')
			{
				if (ft_toupper(fill->map[i + y][j + x]) != fill->fig)
					return (0);
				else if (!fill->x)
					fill->x++;
				else
					return (0);
			}
			x++;
		}
		y++;
	}
	return (fill->x ? 1 : 0);
}

void		fill_place_piece(t_fill *fill)
{
	size_t	i;
	size_t	j;

	i = fill->min[0];
	while (i < fill->max[0])
	{
		j = fill->min[1];
		while (j < fill->max[1])
		{
			if (fill_check_place(fill, i, j))
			{
				if (fill->out_count)
					fill_check_strategy(fill, i, j);
				else
					fill_save_out(fill, i, j);
			}
			j++;
		}
		i++;
	}
	ft_printf("%zu %zu\n", fill->out[0], fill->out[1]);
}