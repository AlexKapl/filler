/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analiz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:48:36 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 02:49:27 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_analize_quater(t_filler *func)
{
	int i;
	int j;

	i = 0;
	while (func->map[i])
	{
		j = 0;
		while (func->map[i][j])
		{
			if (ft_toupper(func->map[i][j]) == func->player)
			{
				if (i < func->row / 2 && j < func->col / 2)
					func->quater = 1;
				else if (i >= func->row / 2 && j >= func->col / 2)
					func->quater = 4;
				else if (i < func->row / 2 && j >= func->col / 2)
					func->quater = 2;
				else
					func->quater = 3;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_begin_coordinate(t_filler *func)
{
	int i;
	int j;

	i = 0;
	while (func->map[i])
	{
		j = 0;
		while (func->map[i][j])
		{
			if (ft_toupper(func->map[i][j]) == func->player)
			{
				func->begin_y = i;
				func->begin_x = j;
			}
			j++;
		}
		i++;
	}
}
