/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:31:27 by akaplyar          #+#    #+#             */
/*   Updated: 2017/04/30 16:33:16 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char **tab, int count)
{
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
		while (count)
			free(tab[count--]);
		ft_memdel((void**)tab);
	}
}
