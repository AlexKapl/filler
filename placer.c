/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:16 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 17:49:32 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fill_check_cords(t_fill *fill, int i, int j)
{
	if (i >= fill->height || j >= fill->width)
		return (0);
	if (fill->map[i][j] != '.')
	{
		if (ft_toupper(fill->map[i][j]) != fill->fig)
			return (0);
		else if (fill->x)
			return (0);
		else
			fill->x++;
	}
	return (1);
}

static int	fill_check_place(t_fill *fill, int i, int j)
{
	int	y;
	int	x;

	y = 0;
	fill->x = 0;
	while (y < fill->p->height)
	{
		x = 0;
		while (x < fill->p->width)
		{
			if (fill->p->place[y][x] != '.')
				if (!(fill_check_cords(fill, i + y, j + x)))
					return (0);
			x++;
		}
		y++;
	}
	return (fill->x ? 1 : 0);
}

static int	fill_check_strategy(t_fill *fill, int i, int j)
{
	int		ss;
	int		gg;

	ss = ft_abs((fill->out[0] - fill->e_pos[0]) +
				(fill->out[1] - fill->e_pos[1]));
	gg = ft_abs((fill->e_pos[0] - i) +
				(fill->e_pos[1] - j));
	if (gg < ss)
		fill_operate_out(fill, i, j, 1);
	return (0);
}

void		fill_place_piece(t_fill *fill)
{
	int	i;
	int	j;

	if (fill_make_shield(fill) > 0)
		return ;
	i = fill->min[0];
	while (i < fill->height)
	{
		j = fill->min[1];
		while (j < fill->width)
		{
			if (fill_check_place(fill, i, j))
			{
				if (fill->out_count)
					fill_check_strategy(fill, i, j);
				else
					fill_operate_out(fill, i, j, 1);
			}
			j++;
		}
		i++;
	}
	fill_operate_out(fill, 0, 0, 0);
}
