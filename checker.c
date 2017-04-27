#include "filler.h"

static void fill_check_piece_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->piece->min_x[1] < j)
	{
		fill->piece->min_x[0] = i;
		fill->piece->min_x[1] = j;
	}
	if (fill->piece->min_y[0] < i)
	{
		fill->piece->min_y[0] = i;
		fill->piece->min_y[1] = j;
	}
	if (fill->piece->max_x[1] > j)
	{
		fill->piece->max_x[0] = i;
		fill->piece->max_x[1] = j;
	}
	if (fill->piece->max_y[0] > i)
	{
		fill->piece->max_y[0] = i;
		fill->piece->max_y[1] = j;
	}
}

static void fill_check_enemy_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->enemy->min_x[1] < j)
	{
		fill->enemy->min_x[0] = i;
		fill->enemy->min_x[1] = j;
	}
	if (fill->enemy->min_y[0] < i)
	{
		fill->enemy->min_y[0] = i;
		fill->enemy->min_y[1] = j;
	}
	if (fill->enemy->max_x[1] > j)
	{
		fill->enemy->max_x[0] = i;
		fill->enemy->max_x[1] = j;
	}
	if (fill->enemy->max_y[0] > i)
	{
		fill->enemy->max_y[0] = i;
		fill->enemy->max_y[1] = j;
	}
}

static void fill_check_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->min_x[1] < j)
	{
		fill->min_x[0] = i;
		fill->min_x[1] = j;
	}
	if (fill->min_y[0] < i)
	{
		fill->min_y[0] = i;
		fill->min_y[1] = j;
	}
	if (fill->max_x[1] > j)
	{
		fill->max_x[0] = i;
		fill->max_x[1] = j;
	}
	if (fill->max_y[0] > i)
	{
		fill->max_y[0] = i;
		fill->max_y[1] = j;
	}
}

void fill_check_piece(t_fill *fill)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < fill->piece->height)
	{
		j = 0;
		while (j < fill->piece->width)
		{
			if (fill->piece->place[i][j] == '*')
				fill_check_piece_edge(fill, i ,j);
		}
		i++;
	}
}

void fill_check_map(t_fill *fill)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < fill->height)
	{
		j = 0;
		while (j < fill->width)
		{
			if (fill->map[i][j] == fill->fig[0] ||
					fill->map[i][j] == fill->fig[1])
				fill_check_edge(fill, i ,j);
			else if (fill->map[i][j] != '.')
				fill_check_enemy_edge(fill, i ,j);
		}
		i++;
	}
}