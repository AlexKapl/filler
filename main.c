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

void		fill_operate_out(t_fill *fill, int i, int j, int save)
{
	if (save)
	{
		fill->out[0] = i;
		fill->out[1] = j;
		fill->out_count++;
	}
	else
		ft_printf("%zu %zu\n", fill->out[0], fill->out[1]);
}

void		fill_free_data(t_fill *fill)
{
	ft_tabdel(fill->map, fill->height);
	ft_tabdel(fill->p->place, fill->p->height);
}

static void	fill_map_init(t_fill *fill)
{
	fill->p = (t_piece*)malloc(sizeof(t_piece));
	fill->pos[0] = 0;
	fill->pos[1] = 0;
	fill->e_pos[0] = 0;
	fill->e_pos[1] = 0;
	fill->c[0] = fill->height / 2;
	fill->c[1] = fill->width / 2;
}

int			main(void)
{
	t_fill	fill;

	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}
