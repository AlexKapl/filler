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
	if (f->map[i][j] == '.')
		if ((i < f->pos[0] && f->q == 3) || (i > f->pos[0] && f->q == 1))
			if (j == f->pos[1] || j == f->width - f->pos[1])
				return (1);
	return (0);
}

static void	fill_check_shield_h(t_fill *fill, int y, int x, int *piece)
{
	int		i;
	int		j;
	int		touch;

	i = 0;
	touch = 0;
	while (i < fill->p->height)
	{
		j = 0;
		while (j < fill->p->width)
		{
			if (fill->p->place[i][j] == '*')
				if (fill_check_quater(fill, i + y, j + x))
					touch++;
			j++;
		}
		i++;
	}
	if (*piece < touch)
	{
		*piece = touch;
		fill_operate_out(fill, y, x, 1);
	}
}

static int	fill_make_shield_h(t_fill *fill)
{
	int		i;
	int		j;
	int		piece;

	piece = 0;
	i = fill->min[0];
	while (i < fill->height)
	{
		j = fill->min[1];
		while (j < fill->width)
		{
			if (fill_check_place(fill, i, j))
				fill_check_shield_h(fill, i, j, &piece);
			j++;
		}
		i++;
	}
	if (piece)
		fill_operate_out(fill, 0, 0, 0);
	else
		fill_operate_out(fill, 0, 0, -1);
	return (piece);
}

static void	fill_check_shield(t_fill *fill, int y, int x, int *piece)
{
	int		i;
	int		j;
	int		touch;

	i = 0;
	touch = 0;
	while (i < fill->p->height)
	{
		j = 0;
		while (j < fill->p->width)
		{
			if (fill->p->place[i][j] == '*')
				if (y + i == fill->pos[0] &&
					fill->map[y + i][x + j] == '.')
					touch++;
			j++;
		}
		i++;
	}
	if (*piece < touch)
	{
		*piece = touch;
		fill_operate_out(fill, y, x, 1);
	}
}

int			fill_make_shield(t_fill *fill)
{
	int		i;
	int		j;
	int		piece;

	piece = 0;
	i = fill->min[0];
	while (i < fill->height)
	{
		j = fill->min[1];
		while (j < fill->width)
		{
			if (fill_check_place(fill, i, j))
				fill_check_shield(fill, i, j, &piece);
			j++;
		}
		i++;
	}
	if (piece)
		fill_operate_out(fill, 0, 0, 0);
	else
		fill_operate_out(fill, 0, 0, -1);
	return (piece > 0 ? 1 : fill_make_shield_h(fill));
}
