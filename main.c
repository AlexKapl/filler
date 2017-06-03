/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:50 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:51 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fill_free_data(t_fill *fill)
{
	ft_tabdel(fill->map, (int)fill->height);
	ft_tabdel(fill->p->place, (int)fill->p->height);
	ft_memdel((void **)fill->p);
	fill->p = NULL;
	fill->map = NULL;
}

static void	fill_map_init(t_fill *fill)
{
	size_t	i;

	i = 0;
	fill->map = (char**)malloc(sizeof(char*) * fill->height);
	while (i < fill->height)
	{
		fill->map[i] = (char*)malloc(fill->width);
		i++;
	}
	fill->pos[0] = 0;
	fill->pos[1] = 0;
	fill->e_pos[0] = 0;
	fill->e_pos[1] = 0;
	fill->c[0] = fill->height / 2;
	fill->c[1] = fill->width / 2;
}

int			main()
{
	t_fill	fill;

	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}
