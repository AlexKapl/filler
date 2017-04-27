#include "filler.h"

void			fill_drop_edge(t_fill *fill)
{
	fill->min_x[0] = fill->height - 1;
	fill->min_x[1] = fill->width - 1;
	fill->min_y[0] = fill->height - 1;
	fill->min_y[1] = fill->width - 1;
	fill->max_x[0] = 0;
	fill->max_x[1] = 0;
	fill->max_y[0] = 0;
	fill->max_y[1] = 0;
	fill->enemy->min_x[0] = fill->height - 1;
	fill->enemy->min_x[1] = fill->width - 1;
	fill->enemy->min_y[0] = fill->height - 1;
	fill->enemy->min_y[1] = fill->width - 1;
	fill->enemy->max_x[0] = 0;
	fill->enemy->max_x[1] = 0;
	fill->enemy->max_y[0] = 0;
	fill->enemy->max_y[1] = 0;
	fill->piece->min_x[0] = fill->piece->height - 1;
	fill->piece->min_x[1] = fill->piece->width - 1;
	fill->piece->min_y[0] = fill->piece->height - 1;
	fill->piece->min_y[1] = fill->piece->width - 1;
	fill->piece->max_x[0] = 0;
	fill->piece->max_x[1] = 0;
	fill->piece->max_y[0] = 0;
	fill->piece->max_y[1] = 0;
}

static void	fill_map_init(t_fill *fill)
{
	size_t	i;

	i = 0;
	fill->map = (char**)malloc(sizeof(char*) * fill->height);
	while (i < fill->height)
	{
		fill->map[i] = (char*)malloc(fill->width);
		i++;
	}
}

int			main()
{
	t_fill	fill;
	t_enemy	enemy;

	fill.enemy = &enemy;
	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}