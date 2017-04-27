#include "filler.h"

void		fill_place_piece(t_fill *fill)
{
	fill_check_map(fill);
	fill_check_piece(fill);
	if (fill->min_x[0] > fill->enemy->max_x[0])
	{
		if (fill->min_y[1] > fill->enemy->max_y[1])
		{
			do;
		}
		else
		{

		}
	}
	else
	{
		if (fill->min_y[1] > fill->enemy->max_y[1])
		{
			do;
		}
		else
		{

		}
	}
}