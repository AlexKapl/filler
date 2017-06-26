#include "stdio.h"
#include "../libft/libft.h"
#include "wchar.h"
#include "locale.h"

//int			main()
//{
//	wchar_t nazi;
//	wchar_t soviet;
//	wchar_t unit;
//	wchar_t *w;
//
//	setlocale(LC_ALL, "");
//	nazi = L'࿖';
//	soviet = L'☭';
//	unit = L'∞';
//	w = L"ઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔ";
//	printf("\e[34m%lc\e[0m \e[31m%lc\e[0m\n", nazi, soviet);
//	printf("%ls\n", w);
//}

static void	ft_tabdeli(char **tab, int count)
{
	int i;

	i = 0;
	if (count < 0)
		while (tab[i])
			free(tab[i++]);
	else
		while (i < count)
			free(tab[i++]);
	free(tab);
}

static void		lol(char ***omg)
{
	int 		i;

	i = 0;
	while (i < 100)
	{
		printf("|%s|\n", (*omg)[i]);
		i++;
	}
}

static void		omfg(char *buff)
{
	free(buff);
	printf("freed\n");
}

int				main()
{
	int			i;
	char		**tab;
	char		*buff;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * 100);
	while (i < 100)
	{
		tab[i] = ft_llitoa(i);
		i++;
	}
	buff = ft_strdup("...................................................................................................");
	lol(&tab);
	ft_tabdeli(tab, 100);
	omfg(buff);
	return 0;
}