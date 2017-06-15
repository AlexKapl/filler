#include "filler.h"

static void	fill_fat_piece(t_fill *fill, size_t **fatmetre)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fill->p->height)
	{
		j = 0;
		*fatmetre[i] = 0;
		while (j < fill->p->width)
		{
			if (fill->p->place[i][j] == '*')
				(*fatmetre[i])++;
			j++;
		}
		i++;
	}
}

static void	fill_check_fat(t_fill *fill, size_t i, size_t j)
{

}

static void	fill_left_shield(t_fill *fill)
{
	size_t	i;
	size_t	j;

	i = fill->min[0];
	while (i < fill->max[0])
	{
		j = fill->min[1];
		while (j < fill->max[1])
		{
			if (fill_check_place(fill, i, j))
			{

			}
			j++;
		}
		i++;
	}
}

static void	fill_right_shield(t_fill *fill)
{
	size_t	i;
	size_t	j;

	i = fill->max[0] - 1;
	while (i >= fill->min[0])
	{
		j = fill->max[1] - 1;
		while (j >= fill->min[1])
		{
			if (fill_check_place(fill, i, j))
			{
				if (fill->out_count)
					fill_check_fat(fill, i, j);
				else
					fill_save_out(fill, i, j);
			}
			j--;
		}
		i--;
	}
}

void		fill_make_shield(t_fill *fill)
{
	size_t	fatmetre[fill->p->height];

	fill_fat_piece(fill, (size_t **)&fatmetre);
	if (fill->pos[1] > fill->c[1])
	{
		if (!fill->sh[0])
			fill_left_shield(fill);
		else
			fill_right_shield(fill);
	}
	else
	{
		if (!fill->sh[1])
			fill_right_shield(fill);
		else
			fill_left_shield(fill);
	}
	ft_printf("{fd}%zu %zu\n", 1, fill->out[0], fill->out[1]);
}