#include "filler.h"

static void fill_check_piece_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->piece->w[1] < j)
	{
		fill->piece->w[0] = i;
		fill->piece->w[1] = j;
	}
	if (fill->piece->n[0] < i)
	{
		fill->piece->n[0] = i;
		fill->piece->n[1] = j;
	}
	if (fill->piece->e[1] >= j)
	{
		fill->piece->e[0] = i;
		fill->piece->e[1] = j;
	}
	if (fill->piece->s[0] >= i)
	{
		fill->piece->s[0] = i;
		fill->piece->s[1] = j;
	}
}

static void fill_check_enemy_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->enemy->w[1] < j)
	{
		fill->enemy->w[0] = i;
		fill->enemy->w[1] = j;
	}
	if (fill->enemy->n[0] < i)
	{
		fill->enemy->n[0] = i;
		fill->enemy->n[1] = j;
	}
	if (fill->enemy->e[1] >= j)
	{
		fill->enemy->e[0] = i;
		fill->enemy->e[1] = j;
	}
	if (fill->enemy->s[0] >= i)
	{
		fill->enemy->s[0] = i;
		fill->enemy->s[1] = j;
	}
}

static void fill_check_edge(t_fill *fill, size_t i, size_t j)
{
	if (fill->w[1] < j)
	{
		fill->w[0] = i;
		fill->w[1] = j;
	}
	if (fill->n[0] < i)
	{
		fill->n[0] = i;
		fill->n[1] = j;
	}
	if (fill->e[1] >= j)
	{
		fill->e[0] = i;
		fill->e[1] = j;
	}
	if (fill->s[0] >= i)
	{
		fill->s[0] = i;
		fill->s[1] = j;
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