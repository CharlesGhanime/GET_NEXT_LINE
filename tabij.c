#include <stdlib.h>
#include <stdio.h>

#define nbLignes 10
#define nbColonnes 10

int		main()
{
	char	tab[nbLignes][nbColonnes];
	int		i;
	int		j;

	i = j = 0;
	while (i < nbLignes)
	{
		j = 0;
		while (j < nbColonnes)
		{
			i = 0;
			tab[i][j] = 'x';
			printf("[%c]\n", tab[i][j]);
			j++;
		}
	tab[i][j] = 'x';
	printf("[%c]", tab[i][j]);
	i++;
	}
	return (0);
}
