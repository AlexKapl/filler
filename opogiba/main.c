/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:50:54 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 02:52:03 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "mlx.h"

void	ft_do_filler_struct(t_filler *func)
{
	g_fd = 0;
	func->map = NULL;
	func->figure = NULL;
	func->row = 0;
	func->col = 0;
	func->player = '\0';
	func->enemy = '\0';
	func->size_fig_x = 0;
	func->size_fig_y = 0;
	func->quater = 0;
}

int		ft_do_attack(t_filler *func, t_coord *cr)
{
	int x_map_coord;
	int y_map_coord;
	int count;

	count = 0;
	y_map_coord = -func->size_fig_y;
	while (y_map_coord < func->row)
	{
		x_map_coord = -func->size_fig_x;
		while (x_map_coord < func->col)
		{
			if (ft_put_figure(y_map_coord, x_map_coord, func))
			{
				count++;
				cr->x_crd = x_map_coord;
				cr->y_crd = y_map_coord;
				if (func->quater == 3 || func->quater == 4)
					return (1);
			}
			x_map_coord++;
		}
		y_map_coord++;
	}
	return (count);
}

void	ft_analize_map(t_filler *func, t_coord *cr)
{
	if (func->quater == 0)
	{
		ft_analize_quater(func);
		ft_begin_coordinate(func);
	}
	if (ft_do_shield(func, cr) > 0)
	{
		ft_printf("%d %d\n", cr->y_crd, cr->x_crd);
		return ;
	}
	if (ft_do_vertical_shield(func, cr) > 0)
	{
		ft_printf("%d %d\n", cr->y_crd, cr->x_crd);
		return ;
	}
	if (ft_do_attack(func, cr))
	{
		ft_printf("%d %d\n", cr->y_crd, cr->x_crd);
		return ;
	}
	ft_printf("0 0\n");
}

int		main(void)
{
	char		*line;
	t_filler	*func;
	t_coord		*cr;

	func = (t_filler *)malloc(sizeof(t_filler));
	cr = (t_coord *)malloc(sizeof(t_coord));
	ft_do_filler_struct(func);
	line = NULL;
	ft_detect_player(func);
	ft_detect_size_map(func);
	while (get_next_line(g_fd, &line) > 0)
	{
		if (line[1] != 'l')
		{
			ft_parsing_map(func);
			ft_detect_figure(func);
			ft_analize_map(func, cr);
		}
		else
			free(line);
	}
	return (0);
}
