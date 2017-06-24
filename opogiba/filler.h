/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 03:02:44 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/30 03:03:55 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft/libft.h"

typedef struct	s_filler
{
	char		player;
	char		enemy;
	int			row;
	int			col;
	char		**map;
	char		**figure;
	int			size_fig_y;
	int			size_fig_x;
	int			quater;
	int			begin_x;
	int			begin_y;

}				t_filler;

typedef struct	s_coord
{
	int			x_crd;
	int			y_crd;
}				t_coord;

int				g_fd;

void			ft_detect_player(t_filler *func);
void			ft_detect_size_map(t_filler *func);
void			ft_parsing_map(t_filler *func);
void			ft_parsing_figure(t_filler *func);
void			ft_detect_figure(t_filler *func);
int				ft_put_figure(int y_crd, int x_crd, t_filler *func);
void			ft_analize_quater(t_filler *func);
void			ft_begin_coordinate(t_filler *func);
int				ft_do_shield(t_filler *func, t_coord *cr);
int				ft_chk_len_shld(t_filler *func, int x, int y);
int				ft_chk_len_ver_shld(t_filler *func, int x, int y);
int				ft_do_vertical_shield(t_filler *func, t_coord *cr);
#endif
