#include "filler.h"

void			fill_drop_edge(t_fill *fill)
{
	fill->w[0] = fill->height - 1;
	fill->w[1] = fill->width - 1;
	fill->n[0] = fill->height - 1;
	fill->n[1] = fill->width - 1;
	fill->e[0] = 0;
	fill->e[1] = 0;
	fill->s[0] = 0;
	fill->s[1] = 0;
	fill->enemy->w[0] = fill->height - 1;
	fill->enemy->w[1] = fill->width - 1;
	fill->enemy->n[0] = fill->height - 1;
	fill->enemy->n[1] = fill->width - 1;
	fill->enemy->e[0] = 0;
	fill->enemy->e[1] = 0;
	fill->enemy->s[0] = 0;
	fill->enemy->s[1] = 0;
	fill->piece->w[0] = fill->piece->height - 1;
	fill->piece->w[1] = fill->piece->width - 1;
	fill->piece->n[0] = fill->piece->height - 1;
	fill->piece->n[1] = fill->piece->width - 1;
	fill->piece->e[0] = 0;
	fill->piece->e[1] = 0;
	fill->piece->s[0] = 0;
	fill->piece->s[1] = 0;
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
	fill.front = 0;
	fill_get_info(&fill);
	fill_map_init(&fill);
	fill_reader(&fill);
	return (0);
}