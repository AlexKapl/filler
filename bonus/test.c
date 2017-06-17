#include "stdio.h"
#include "../libft/libft.h"
#include "wchar.h"
#include "locale.h"

int			main()
{
	wchar_t nazi;
	wchar_t soviet;
	wchar_t unit;
	wchar_t *w;

	setlocale(LC_ALL, "");
	nazi = L'࿖';
	soviet = L'☭';
	unit = L'∞';
	w = L"ઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔઍઐઑઔએઐઑઔ";
	printf("\e[34m%lc\e[0m \e[31m%lc\e[0m\n", nazi, soviet);
	printf("%ls\n", w);
}
