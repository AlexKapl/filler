/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_detect_figure.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:57:50 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 02:58:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_detect_figure(t_filler *func)
{
	int		i;
	char	*line;

	line = NULL;
	i = 6;
	get_next_line(g_fd, &line);
	func->size_fig_y = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	func->size_fig_x = ft_atoi(line + i);
	free(line);
	ft_parsing_figure(func);
}

void	ft_parsing_figure(t_filler *func)
{
	int		i;
	int		j;
	char	*tmp;
	char	*line;

	line = NULL;
	i = func->size_fig_y;
	j = 0;
	if (func->figure)
		ft_clean_two_char(func->figure);
	func->figure = (char **)malloc(sizeof(char *) * (func->size_fig_y + 1));
	while (i > 0)
	{
		get_next_line(g_fd, &line);
		tmp = line;
		func->figure[j++] = ft_strdup(line);
		free(tmp);
		i--;
	}
	func->figure[j] = NULL;
}
