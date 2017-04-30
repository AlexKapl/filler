#include "filler.h"

int			fill_place_check(t_fill *f, t_piece *p, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	i = p->n[1];
	while (i < p->s[1])
	{
		j = p->w[0];
		while (j < p->e[0])
		{
			if (f->map[x + j][y + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		fill_place_w(t_fill *fill)
{
	size_t	i;
	size_t	j;

	i = fill->w[1];
	while (i > 0)
	{
		j = fill->w[0];
		while (j > 0)
		{

			j--;
		}
		i--;
	}
}

void		fill_place_piece(t_fill *fill)
{
	fill_check_map(fill);
	fill_check_piece(fill);
	if (fill->w[0] > fill->enemy->w[0])
	{
		if (fill->n[1] > fill->enemy->s[1])
			fill_place_w(fill);
		else
		{
			somth;
		}
	}
	else
	{
		if (fill->n[1] > fill->enemy->s[1])
		{
			shit;
		}
		else
		{
			omfg;
		}
	}
}