/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:50 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 17:46:36 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_map_init(t_fill *fill)
{
	fill->fig = '\0';
	fill->map = NULL;
	fill->height = 0;
	fill->width = 0;
	fill->pos[0] = 0;
	fill->pos[1] = 0;
	fill->min[0] = 0;
	fill->min[1] = 0;
	fill->out[0] = 0;
	fill->out[1] = 0;
	fill->out_count = 0;
	fill->e_pos[0] = 0;
	fill->e_pos[1] = 0;
	fill->c[0] = 0;
	fill->c[1] = 0;
	fill->q = 0;
	fill->x = 0;
	fill->p = (t_piece*)malloc(sizeof(t_piece));
	fill->p->place = NULL;
	fill->p->height = 0;
	fill->p->width = 0;
}

void		fill_operate_out(t_fill *fill, int i, int j, int save)
{
	if (!save)
		ft_printf("%zu %zu\n", fill->out[0], fill->out[1]);
	else if (save > 0)
	{
		fill->out[0] = i;
		fill->out[1] = j;
		fill->out_count++;
	}
	else
	{
		fill->out[0] = 0;
		fill->out[1] = 0;
		fill->out_count = 0;
	}
}

int			main(void)
{
	t_fill	fill;

	fill_map_init(&fill);
	fill_get_info(&fill);
	fill_reader(&fill);
	return (0);
}
