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

# define N 0
# define E 1
# define W 2
# define S 3

typedef struct	s_enemy
{
	char		fig[2];
	size_t		w[2];
	size_t		n[2];
	size_t		e[2];
	size_t		s[2];
}				t_enemy;

typedef struct	s_piece
{
	char		**place;
	size_t		width;
	size_t		height;
	size_t		w[2];
	size_t		n[2];
	size_t		e[2];
	size_t		s[2];
}				t_piece;

typedef struct	s_fill
{
	char		fig[2];
	char		**map;
	size_t		width;
	size_t		height;
	size_t		w[2];
	size_t		n[2];
	size_t		e[2];
	size_t		s[2];
	size_t		c[2];
	t_piece		*piece;
	t_enemy		*enemy;
}				t_fill;

void			fill_reader(t_fill *fill);
void			fill_get_info(t_fill *fill);
void			fill_drop_edge(t_fill *fill);
void			fill_place_piece(t_fill *fill);
void			fill_check_map(t_fill *fill);
void			fill_check_piece(t_fill *fill);
#endif
