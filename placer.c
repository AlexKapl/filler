/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:26:16 by akaplyar          #+#    #+#             */
/*   Updated: 2017/05/11 16:26:16 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			fill_place_check(t_fill *f, t_piece *p, size_t x, size_t y)
{
	size_t	i;
	size_t	j;
	int		touch;

	i = p->n[1];
	touch = 0;
	while (i < p->s[1])
	{
		j = p->w[0];
		while (j < p->e[0])
		{
			if (f->map[x + j][y + i] != '.')
			{
				if (f->map[x + j][y + i] == f->enemy->fig[0] ||
						f->map[x + j][y + i] == f->enemy->fig[1])
					return (0);
				touch++;
				if (touch > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (touch ? 1 : 0);
}

int			fill_place_wn(t_fill *fill)
{
	size_t	i;
	size_t	j;
	t_piece	*p;

	p = fill->piece;
	j = fill->w[1];
	while (j < fill->e[1])
	{
		i = fill->w[0];
		while (i < fill->e[0])
		{
			if (i >= p->height && j >= p->width)
				if (fill_place_check(fill, p, i - p->height + 1, j - p->width + 1))
				{
					ft_printf("%zu %zu\n", i - p->height + 1, j - p->width + 1);
					return (1);
				}
			i++;
		}
		j++;
	}
	return (0);
}

int			fill_place_ws(t_fill *fill)
{
	size_t	i;
	size_t	j;
	t_piece	*p;

	p = fill->piece;
	j = fill->w[1];
	while (j < fill->e[1])
	{
		i = fill->w[0];
		while (i < fill->e[0])
		{
			if (i + p->height < fill->height && j >= p->width)
				if (fill_place_check(fill, p, i + p->height - 1, j - p->width + 1))
				{
					ft_printf("%zu %zu\n", i + p->height - 1, j - p->width + 1);
					return (1);
				}
			i++;
		}
		j++;
	}
	return (0);
}

int			fill_place_en(t_fill *fill)
{
	size_t	i;
	size_t	j;
	t_piece	*p;

	p = fill->piece;
	j = fill->w[1];
	while (j > 0)
	{
		i = fill->w[0];
		while (i > 0)
		{
			if (i >= p->height && j + p->width < fill->width)
				if (fill_place_check(fill, p, i - p->height + 1, j + p->width - 1))
				{
					ft_printf("%zu %zu\n", i - p->height + 1, j + p->width - 1);
					return (1);
				}
			i--;
		}
		j--;
	}
	return (0);
}


int			fill_place_es(t_fill *fill)
{
	size_t	i;
	size_t	j;
	t_piece	*p;

	p = fill->piece;
	j = fill->w[1];
	while (j < fill->width)
	{
		i = fill->w[0];
		while (i < fill->height)
		{
			if (i + p->height < fill->height && j + p->width < fill->width)
				if (fill_place_check(fill, p, i + p->height - 1, j + p->width - 1))
				{
					ft_printf("%zu %zu\n", i + p->height - 1, j + p->width - 1);
					return (1);
				}
			i++;
		}
		j++;
	}
	return (0);
}

void		fill_place_piece(t_fill *fill)
{
	fill_check_map(fill);
	fill_check_piece(fill);
	if (fill->w[1] >= fill->enemy->e[1])
	{
		if (fill->n[0] <= fill->enemy->s[0])
			fill_place_wn(fill);
		else
			fill_place_ws(fill);
	}
	else if (fill->e[1] <= fill->enemy->w[1])
	{
		if (fill->n[0] <= fill->enemy->s[0])
			fill_place_en(fill);
		else
			fill_place_es(fill);
	}
}
