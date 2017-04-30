#include "filler.h"

void		fill_get_info(t_fill *fill)
{
	char	*buff;
	char	*tmp;

	get_next_line(0, &buff);
	tmp = ft_strchr(buff, 'p');
	fill->fig[0] = (char)(*(tmp + 1) == '2' ? 'x' : 'o');
	fill->fig[1] = (char)(fill->fig[0] - 32);
	fill->enemy->fig[0] = (char)(fill->fig[0] == 'x' ? 'o' : 'x');
	fill->enemy->fig[1] = (char)(fill->enemy->fig[0] - 32);
	free(buff);
	get_next_line(0, &buff);
	tmp = buff + 8;
	fill->height = (size_t)ft_atoi(tmp);
	while (isdigit(*tmp))
		tmp++;
	fill->width = (size_t)ft_atoi(tmp);
	free(buff);
}

static void	fill_read_piece(t_fill *fill, int fd)
{
	char	*buff;
	char	**tmp;
	t_piece	piece;
	size_t	i;

	i = 0;
	get_next_line(0, &buff);
	tmp = ft_strsplit(buff, ' ');
	free(buff);
	piece.height = (size_t)ft_atoi(tmp[1]);
	piece.width = (size_t)ft_atoi(tmp[2]);
	ft_tabdel(tmp, -1);
	piece.place = (char**)malloc(sizeof(char*) * piece.height);
	while (i++ < piece.height)
	{
		get_next_line(0, &buff);
		piece.place[i] = ft_strdup(buff);
		ft_printf("{fd}%s\n", fd, piece.place[i]);
		free(buff);
	}
	ft_printf("{fd}\n\n", fd);
	fill->piece = &piece;
}

static void	fill_read_map(t_fill *fill, int fd)
{
	size_t	i;
	char	*buff;

	i = 0;
	while (i < fill->height)
	{
		get_next_line(0, &buff);
		free(fill->map[i]);
		fill->map[i] = ft_strsub(buff, 4, fill->width);
		ft_printf("{fd}%s\n", fd, fill->map[i]);
		free(buff);
		i++;
	}
	fill_drop_edge(fill);
	ft_printf("{fd}\n\n", fd);
}

void		fill_reader(t_fill *fill)
{
	char	*buff;
	int		fd;
	int		fd1;

	fd = open("log", O_WRONLY);
	fd1 = open("piece", O_WRONLY);
	while (get_next_line(0, &buff) > 0)
	{
		if (*buff == ' ')
			fill_read_map(fill, fd);
		else if (ft_strstr(buff, "Piece"))
		{
			fill_read_piece(fill, fd1);
//			fill_place_piece(fill);
		}
		free(buff);
	}
	close(fd);
	close(fd1);
}