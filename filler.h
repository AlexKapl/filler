/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:35 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:36 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>
# include "errno.h"


typedef struct	s_piece
{
	char		**place;
	size_t		width;
	size_t		height;
}				t_piece;

typedef struct	s_fill
{
	char		fig;
	char		**map;
	size_t		width;
	size_t		height;
	size_t		pos[2];
	size_t		edge[2];
	size_t		min[2];
	size_t		max[2];
	size_t		out[2];
	size_t		out_count;
	size_t		e_pos[2];
	size_t		x;
	size_t		c[2];
	size_t		sh[2];
	t_piece		*p;
}				t_fill;

void			fill_reader(t_fill *fill);
void			fill_drop_pos(t_fill *fill);
void			fill_get_info(t_fill *fill);
void			fill_check_map(t_fill *fill);
void			fill_free_data(t_fill *fill);
void			fill_place_piece(t_fill *fill);
int				fill_make_shield(t_fill *fill, size_t i, size_t j);
#endif