#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int		stock(char **overflow, char **line, int *compteur)
{
	int		i;
	char	*save;

	i = 0;
	while ((*overflow)[i])
		if ((*overflow)[i] == '\n')
		{
			save = memalloc((strlen(*overflow) - i) * sizeof(char));
			if (!save)
				return (-1);
			save = strcpy(save, &((*overflow)[i + 1]));
			*line = strncpy(*line, *overflow, i);
			(*line)[i++] = '\0';
			free(*overflow);
			*overflow = save;
			return (1);
		}
		else
			i++;
	*compteur += i;
	*line = strncpy(*line, *overflow, i);
	*line = (char *)realloc(*line, *compteur, *compteur + BUFF_SIZE + 1);
	free(*overflow);
	*overflow = NULL;
	return (0);
}

int		line_split(char **overflow, char **line, int *compteur)
{
	int	i;

	(*line)[*compteur] = '\0';
	i = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
		{
			if ((*line)[i + 1])
			{
				*overflow = (char *)memalloc((*compteur - i) * sizeof(char));
				if (!*overflow)
					return (-1);
				*overflow = strncpy(*overflow, (*line + i + 1), *compteur - i);
				(*overflow)[*compteur - i - 1] = '\0';
			}
			(*line)[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

int		initialisation(const int fd, char ***line, char ***overflow)
{
	if (fd < 0 || fd > 5000 || !*line || FDS <= 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!*overflow)
	{
		if (!(*overflow = (char **)memalloc(FDS * sizeof(char *))))
			return (-1);
	}
	if (!(**line = (char *)memalloc((BUFF_SIZE + 1) * sizeof(char))))
	{
		free(*overflow);
		return (-1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	char	**overflow;
	int				r;
	int				compteur;
	int				resultat;

	compteur = 0;
	if (initialisation(fd, &line, &overflow))
		return (-1);
	if (overflow[fd] && (resultat = stock(&(overflow[fd]), line, &compteur)))
		return (resultat);
	while ((r = read(fd, (*line + compteur), BUFF_SIZE)) > 0 && (compteur += r))
		if ((resultat = line_split(&(overflow[fd]), line, &compteur)))
			return (resultat);
		else if (r == BUFF_SIZE)
		{
			*line = (char *)realloc(*line, compteur * sizeof(char),
					(compteur + BUFF_SIZE + 1) * sizeof(char));
			if (!*line)
				return (-1);
		}
	if (r < 0 || ((*line)[compteur] = '\0'))
		return (-1);
	return (**line ? 1 : 0);
}
