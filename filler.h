/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:35 by akaplyar          #+#    #+#             */
/*   Updated: 2017/06/23 17:59:20 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>
# include "errno.h"

typedef struct	s_piece
{
	char		**place;
	int			height;
	int			width;
}				t_piece;

typedef struct	s_fill
{
	char		fig;
	char		**map;
	int			height;
	int			width;
	int			pos[2];
	int			min[2];
	int			max[2];
	int			out[2];
	int			out_count;
	int			e_pos[2];
	int			x;
	int			c[2];
	t_piece		*p;
}				t_fill;

int				fill_make_shield(t_fill *fill);
int				fill_check_place(t_fill *fill, int i, int j);
void			fill_reader(t_fill *fill);
void			fill_drop_pos(t_fill *fill);
void			fill_get_info(t_fill *fill);
void			fill_check_map(t_fill *fill);
void			fill_free_data(t_fill *fill);
void			fill_place_piece(t_fill *fill);
void			fill_operate_out(t_fill *fill, int i, int j, int save);
#endif
