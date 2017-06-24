/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_shield.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:49:46 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 02:57:25 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_chk_len_shld(t_filler *func, int x, int y)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (func->figure[i])
	{
		j = 0;
		while (func->figure[i][j])
		{
			if (func->figure[i][j] == '*')
			{
				if (i + y == func->begin_y
					&& func->map[i + y][j + x] != func->player)
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int		ft_do_shield(t_filler *func, t_coord *cr)
{
	int x_map_coord;
	int y_map_coord;
	int count;

	count = -1;
	y_map_coord = -func->size_fig_y;
	while (y_map_coord < func->row)
	{
		x_map_coord = -func->size_fig_x;
		while (x_map_coord < func->col)
		{
			if (ft_put_figure(y_map_coord, x_map_coord, func))
			{
				if (count < ft_chk_len_shld(func, x_map_coord, y_map_coord))
				{
					count = ft_chk_len_shld(func, x_map_coord, y_map_coord);
					cr->x_crd = x_map_coord;
					cr->y_crd = y_map_coord;
				}
			}
			x_map_coord++;
		}
		y_map_coord++;
	}
	return (count);
}

int		ft_chk_len_ver_shld(t_filler *func, int x, int y)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (func->figure[i])
	{
		j = 0;
		while (func->figure[i][j])
		{
			if (func->figure[i][j] == '*'
					&& ((i + y < func->begin_y && func->quater == 4)
						|| (i + y > func->begin_y && func->quater == 1)))
			{
				if ((j + x == func->begin_x
							&& func->map[i + y][j + x] != func->player) ||
						(j + x == func->row - func->begin_x
							&& func->map[i + y][j + x] != func->player))
					count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int		ft_do_vertical_shield(t_filler *func, t_coord *cr)
{
	int x_map_coord;
	int y_map_coord;
	int count;
	int tmp_count;

	count = -1;
	y_map_coord = -func->size_fig_y;
	while (y_map_coord < func->row)
	{
		x_map_coord = -func->size_fig_x;
		while (x_map_coord < func->col)
		{
			if (ft_put_figure(y_map_coord, x_map_coord, func))
			{
				if (count < (tmp_count = ft_chk_len_ver_shld(func,
								x_map_coord, y_map_coord)))
				{
					count = tmp_count;
					cr->x_crd = x_map_coord;
					cr->y_crd = y_map_coord;
				}
			}
			x_map_coord++;
		}
		y_map_coord++;
	}
	return (count);
}
