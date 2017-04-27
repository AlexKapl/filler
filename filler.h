#ifndef FILLER_H
#define FILLER_H

# include "libft/libft.h"
# include <fcntl.h>
# include "errno.h"

typedef struct	s_enemy
{
	size_t		min_x[2];
	size_t		min_y[2];
	size_t		max_x[2];
	size_t		max_y[2];
}				t_enemy;

typedef struct	s_piece
{
	char		**place;
	size_t		width;
	size_t		height;
	size_t		min_x[2];
	size_t		min_y[2];
	size_t		max_x[2];
	size_t		max_y[2];
}				t_piece;

typedef struct	s_fill
{
	char		fig[2];
	char		**map;
	size_t		width;
	size_t		height;
	size_t		min_x[2];
	size_t		min_y[2];
	size_t		max_x[2];
	size_t		max_y[2];
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