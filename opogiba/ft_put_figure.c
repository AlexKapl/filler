/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:59:36 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 03:00:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_put_figure(int y_crd, int x_crd, t_filler *func)
{
	int i;
	int j;
	int intresection;

	i = 0;
	intresection = 0;
	while (func->figure[i])
	{
		j = 0;
		while (func->figure[i][j])
		{
			if (func->figure[i][j] == '*')
			{
				if (i + y_crd < 0 || i + y_crd >= func->row ||
						j + x_crd < 0 || j + x_crd >= func->col)
					return (0);
				if (ft_toupper(func->map[i + y_crd][j + x_crd]) == func->player)
					intresection++;
				if (ft_toupper(func->map[i + y_crd][j + x_crd]) == func->enemy)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (intresection == 1)
		return (1);
	return (0);
}
