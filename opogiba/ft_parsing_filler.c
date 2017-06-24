/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_filler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:53:24 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 02:59:19 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_detect_size_map(t_filler *func)
{
	int		i;
	char	*line;

	line = NULL;
	i = 8;
	get_next_line(g_fd, &line);
	func->row = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	func->col = ft_atoi(line + i);
	free(line);
}

void	ft_parsing_map(t_filler *func)
{
	int		i;
	int		j;
	char	*tmp;
	char	*line;

	line = NULL;
	i = func->row;
	j = 0;
	if (func->map)
		ft_clean_two_char(func->map);
	func->map = (char **)malloc(sizeof(char *) * (func->row + 1));
	while (i > 0)
	{
		get_next_line(g_fd, &line);
		tmp = line;
		func->map[j++] = ft_strsub(line, 4, ft_strlen(line));
		free(tmp);
		i--;
	}
	func->map[j] = NULL;
}

void	ft_detect_player(t_filler *func)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	get_next_line(g_fd, &line);
	while (line[i])
	{
		if (line[i] == 'p')
		{
			i++;
			if (line[i] == '1')
				func->player = 'O';
			else
				func->player = 'X';
			break ;
		}
		i++;
	}
	func->enemy = func->player == 'O' ? 'X' : 'O';
	free(line);
	line = NULL;
}
