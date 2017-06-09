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

void	ft_tabdeli(char **tab, int count)
{
	int i;

	i = 0;
	if (count < 0)
	{
		while (*tab)
		{
			free(*tab);
			tab++;
		}
		ft_memdel((void**)tab);
	}
	else
	{
		while (i < count)
			free(tab[i++]);
//		ft_memdel((void**)tab);
	}
}

void		fill_free_data(t_fill *fill)
{
	ft_tabdeli(fill->map, (int)fill->height);
	ft_tabdeli(fill->p->place, (int)fill->p->height);
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

int			main()
{
	t_fill	fill;

	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}
