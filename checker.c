/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:11 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 17:46:11 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_drop_pos(t_fill *fill)
{
	fill->min[0] = fill->height - 1;
	fill->min[1] = fill->width - 1;
	fill->out_count = 0;
	fill->out[0] = 0;
	fill->out[1] = 0;
}

static void	fill_get_edge(t_fill *fill)
{
	fill->min[0] -= (fill->p->height - 1);
	if (fill->min[0] < 0)
		fill->min[0] = 0;
	fill->min[1] -= (fill->p->width - 1);
	if (fill->min[1] < 0)
		fill->min[1] = 0;
}

static void	fill_check_pos(t_fill *fill, int i, int j)
{
	if (fill->min[0] > i)
		fill->min[0] = i;
	if (fill->min[1] > j)
		fill->min[1] = j;
	if (!fill->pos[0] && !fill->pos[1])
	{
		fill->pos[0] = i;
		fill->pos[1] = j;
		if (i < fill->c[0])
		{
			if (j < fill->c[1])
				fill->q = 1;
			else
				fill->q = 2;
		}
		else
		{
			if (j >= fill->c[1])
				fill->q = 3;
			else
				fill->q = 4;
		}
	}
}

void		fill_check_map(t_fill *fill)
{
	int i;
	int j;

	i = 0;
	fill_drop_pos(fill);
	while (i < fill->height)
	{
		j = 0;
		while (j < fill->width)
		{
			if (ft_toupper(fill->map[i][j]) == fill->fig)
				fill_check_pos(fill, i, j);
			else if ((!fill->e_pos[0] && !fill->e_pos[1])
					 && fill->map[i][j] != '.')
			{
				fill->e_pos[0] = i;
				fill->e_pos[1] = j;
			}
			j++;
		}
		i++;
	}
	fill_get_edge(fill);
}
