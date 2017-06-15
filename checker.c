/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:11 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:12 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_drop_pos(t_fill *fill)
{
	fill->max[0] = 0;
	fill->max[1] = 0;
	fill->min[0] = fill->height - 1;
	fill->min[1] = fill->width - 1;
	fill->out_count = 0;
	fill->out[0] = 0;
	fill->out[1] = 0;
}

static void	fill_check_pos(t_fill *fill, size_t i, size_t j)
{
	if (fill->min[0] > i)
		fill->min[0] = i;
	if (fill->min[1] > j)
		fill->min[1] = j;
	if (fill->max[0] < i)
		fill->max[0] = i;
	if (fill->max[1] < j)
		fill->max[1] = j;
	if (!fill->pos[0] && !fill->pos[1])
	{
		fill->pos[0] = i;
		fill->pos[1] = j;
		if (fill->pos[0] > fill->c[0])
			fill->edge[0] = 0;
		else
			fill->edge[0] = fill->height - 1;
		if (fill->pos[1] > fill->c[1])
			fill->edge[1] = 0;
		else
			fill->edge[1] = fill->width - 1;
	}
}

static void	fill_get_edge(t_fill *fill)
{
	if (fill->min[0] <= (fill->p->height - 1))
		fill->min[0] = 0;
	else
		fill->min[0] -= (fill->p->height - 1);
	if (fill->min[1] <= (fill->p->width - 1))
		fill->min[0] = 0;
	else
		fill->min[1] -= (fill->p->width - 1);
	while (fill->max[0] + fill->p->height - 1 > fill->height)
		fill->max[0]--;
	while (fill->max[0] + fill->p->height - 1 < fill->height)
		fill->max[0]++;
	if (fill->max[0] == fill->min[0])
		fill->max[0]++;
	while (fill->max[1] + fill->p->width - 1 > fill->width)
		fill->max[1]--;
	while (fill->max[1] + fill->p->width - 1 < fill->width)
		fill->max[1]++;
	if (fill->max[1] == fill->min[1])
		fill->max[1]++;
}

void fill_check_map(t_fill *fill)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < fill->height)
	{
		j = 0;
		while (j < fill->width)
		{
			if (ft_toupper(fill->map[i][j]) == fill->fig)
				fill_check_pos(fill, i ,j);
			else if (fill->map[i][j] != '.'
					 && !fill->e_pos[0] && !fill->e_pos[1])
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