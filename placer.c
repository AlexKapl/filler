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

	if (way)
	{
		ss = ft_abs(((int)fill->out[0] - (int)fill->pos[0]) +
					((int)fill->out[1] - (int)fill->pos[1]));
		gg = ft_abs(((int)fill->pos[0] - (int)i) + ((int)fill->pos[1] - (int)j));
	}
	else
	{
		ss = ft_abs(((int)fill->out[0] - (int)fill->e_pos[0]) +
					((int)fill->out[1] - (int)fill->e_pos[1]));
		gg = ft_abs(((int)fill->e_pos[0] - (int)i) + ((int)fill->e_pos[1] - (int)j));
	}
	if (gg < ss)
		fill_save_out(fill, i, j);
}

static void	fill_check_strategy(t_fill *fill, size_t i, size_t j)
{
	size_t	way_out;
	char	**m;
	size_t	x;
	size_t	y;

	y = fill->c[0];
	x = fill->c[1];
	m = fill->map;
	if (m[y][x] == '.' && m[y][x + 1] == '.' && m[y + 1][x + 1] == '.' &&
		m[y + 1][x] == '.' && m[y + 1][x - 1] == '.' && m[y][x - 1] == '.' &&
		m[y - 1][x - 1] == '.' && m[y - 1][x] == '.' && m[y - 1][x + 1] == '.')
		way_out = 1;
	else if (m[fill->pos[0]][fill->edge[1]] == '.' &&
			m[fill->edge[0]][fill->pos[1]] == '.')
		way_out = 0;
	else
		way_out = 1;
	fill_apply_strategy(fill, i, j, way_out);
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
	ft_printf("{fd}%zu %zu\n", 1, fill->out[0], fill->out[1]);
}