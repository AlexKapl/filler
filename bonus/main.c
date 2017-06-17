#include "stdio.h"
#include "../libft/libft.h"
#include "wchar.h"
#include "locale.h"

static void soviet_win(void)
{
	printf("\e[31m   SSSSSS      SSSS    SS      SS "
				   " SS  SSSSSS SSSSSSSS  SS          SS  SS SS    SS\e[0m\n");
	printf("\e[31m  SS         SS    SS   SS    SS  "
				   " SS  SS        SS      SS        SS   SS SSS   SS\e[0m\n");
	printf("\e[31m   SSSSSS    SS    SS    SS  SS   "
				   " SS  SSSSSS    SS       SS  SS  SS    SS SS S  SS\e[0m\n");
	printf("\e[31m        SS   SS    SS     SSSS    "
				   " SS  SS        SS        SS SS SS     SS SS  S SS\e[0m\n");
	printf("\e[31m   SSSSSS      SSSS        SS     "
				   " SS  SSSSSS    SS         SS  SS      SS SS   SSS\e[0m\n");
}

static void	print_winner(char *buff)
{
	int		nazi;
	int		soviet;

	soviet = ft_atoi(buff + 9);
	get_line_by_line(0, &buff);
	nazi = ft_atoi(buff + 9);
	free(buff);
	printf("\e[34mNAZI == %d\n\e[31mSOVIET == %d\e[0m\n", nazi, soviet);
	if (nazi > soviet)
	{
		printf("\e[34m NN    NN     NN     NNNNNNNN NN "
					   "NN          NN NN NN    NN\e[0m\n");
		printf("\e[34m NNN   NN    NNNN         NN  NN "
					   " NN        NN  NN NNN   NN\e[0m\n");
		printf("\e[34m NN N  NN   NN  NN      NN    NN "
					   "  NN  NN  NN   NN NN N  NN\e[0m\n");
		printf("\e[34m NN  N NN  NNNNNNNN   NN      NN "
					   "   NN NN NN    NN NN  N NN\e[0m\n");
		printf("\e[34m NN   NNN NN      NN NNNNNNNN NN "
					   "    NN  NN     NN NN   NNN\e[0m\n");
	}
	else
		soviet_win();
}

static void	print_line(char *line)
{
	int				i;
	static wchar_t	nazi =  L'࿖';
	static wchar_t	soviet = L'☭';
	static wchar_t	infin =  L'∞';

	i = 0;
	printf("\e[33m%c\e[0m", '|');
	while (line[i])
	{
		if (line[i] == 'X' || line[i] == 'x')
			printf("\e[34m%lc\e[0m", nazi);
		if (line[i] == 'O' || line[i] == 'o')
			printf("\e[31m%lc\e[0m", soviet);
		if (line[i] == '.')
			printf("\e[33m%lc\e[0m", infin);
		i++;
	}
	printf("\e[33m%c\n\e[0m", '|');
	free(line);
}

static void	read_map(int size[2])
{
	static char	*line;
	char		*buff;
	int			j;

	j = -1;
	get_line_by_line(0, &buff);
	free(buff);
	if (!line)
	{
		line = ft_strnew(size[1]);
		ft_memset(line, '_', size[1]);
	}
	printf(" \e[33m%s\n\e[0m", line);
	while (++j < size[0])
	{
		get_line_by_line(0, &buff);
		print_line(ft_strdup(buff + 4));
		free(buff);
	}
	printf(" \e[33m%s\n\e[0m", line);
}

int			main()
{
	char	*buff;
	int		size[2];

	buff = NULL;
	size[0] = -1;
	setlocale(LC_ALL, "");
	while (get_line_by_line(0, &buff))
	{
		if (buff[1] == 'l')
		{
			if (size[0] == -1)
			{
				size[0] = ft_atoi(buff + 8);
				size[1] = ft_atoi(buff + 10);
			}
			read_map(size);
		}
		else if (buff[1] == '=')
			print_winner(buff);
		free(buff);
	}
	return (0);
}