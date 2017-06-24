/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 17:49:43 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 17:50:03 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	fill_check_quater(t_fill *f, int i, int j)
{
	if (f->map[i][j] != f->fig)
		if ((i < f->pos[0] && f->q == 3) || (i > f->pos[0] && f->q == 1))
			if (j == f->pos[1] || j == f->width - f->pos[1])
				return (1);
	return (0);
}

static void	fill_check_shield_h(t_fill *fill, int y, int x, int count[2])
{
	int		i;
	int		j;

	i = 0;
	count[1] = 0;
	while (i < fill->p->height)
	{
		j = 0;
		while (j < fill->p->width)
		{
			if (fill->p->place[i][j] == '*')
				if (fill_check_quater(fill, i + y, j + x))
					count[1]++;
			j++;
		}
		i++;
	}
	if (count[0] < count[1])
	{
		count[0] = count[1];
		fill_operate_out(fill, y, x, 1);
	}
}

static int	fill_make_shield_h(t_fill *fill)
{
	int		i;
	int		j;
	int		count[2];

	count[0] = -1;
	i = fill->min[0];
	while (i < fill->height)
	{
		j = fill->min[1];
		while (j < fill->width)
		{
			if (fill_check_place(fill, i, j))
				fill_check_shield_h(fill, i, j, count);
			j++;
		}
		i++;
	}
	if (count[0] > 0)
		fill_operate_out(fill, 0, 0, 0);
	else
		fill->out_count = 0;
	return (count[0]);
}

static void	fill_check_shield(t_fill *fill, int y, int x, int count[2])
{
	int		i;
	int		j;

	i = 0;
	count[1] = 0;
	while (i < fill->p->height)
	{
		j = 0;
		while (j < fill->p->width)
		{
			if (fill->p->place[i][j] == '*')
				if (y + i == fill->pos[0] &&
					fill->map[i + y][j + x] != fill->fig)
					count[1]++;
			j++;
		}
		i++;
	}
	if (count[0] < count[1])
	{
		count[0] = count[1];
		fill_operate_out(fill, y, x, 1);
	}
}

int			fill_make_shield(t_fill *fill)
{
	int		i;
	int		j;
	int		count[2];

	count[0] = -1;
	i = fill->min[0];
	while (i < fill->height)
	{
		j = fill->min[1];
		while (j < fill->width)
		{
			if (fill_check_place(fill, i, j))
				fill_check_shield(fill, i, j, count);
			j++;
		}
		i++;
	}
	if (count[0] > 0)
		fill_operate_out(fill, 0, 0, 0);
	else
		fill->out_count = 0;
	return (count[0] > 0 ? 1 : fill_make_shield_h(fill));
}
