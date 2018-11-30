/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainee.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:26:46 by cghanime          #+#    #+#             */
/*   Updated: 2018/11/30 18:26:51 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/******************************************************************************/
/***************************STRUCTURE D'UN ELEMENT*****************************/
/******************************************************************************/

typedef struct Element Element;
struct Element
{
	int	*nombre;
	Element *suivant;
};

/******************************************************************************/
/***************************STRUCTURE DE CONTROLE******************************/
/******************************************************************************/

typedef struct Liste Liste;
struct Liste
{
	Element *premier;
};

/******************************************************************************/
/*********************INITIALISATION DE LA LISTE CHAINEE***********************/
/******************************************************************************/

Liste	*initialisation(void)
{
	Liste *liste = malloc(sizeof(*liste));
	Element	*element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
	{
		return (NULL);
	}

	element->nombre = 0;
	element->suivant = NULL;
	liste->premier = element;

	return (liste);
}

/******************************************************************************/
/*************************PUTCHAR && PUTSTR************************************/
/******************************************************************************/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	while (s && *s)
		ft_putchar(*s++);
}	

/******************************************************************************/
/*******************INSERTION D'UN NOUVEAU MAILLON*****************************/
/******************************************************************************/

void	insertion(Liste *liste, int nvNombre)
{
	/* Creation d'un nouvel element */
	Element *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		exit(EXIT_FAILURE);
	nouveau->nombre = nvNombre;

	/* Insertion de l'element au debut de la liste  */
	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
}

/******************************************************************************/
/*********************SUPPRESSION DE LA LISTE CHAINEE**************************/
/******************************************************************************/

void	suppression(Liste *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (liste->premier != NULL)
	{
		Element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
}

/******************************************************************************/
/**********************AFFICHAGE DE LA LISTE CHAINEE***************************/
/******************************************************************************/

void	afficherListe(Liste *liste)
{
	if (liste == NULL)
		exit (EXIT_FAILURE);
	Element *actuel = liste->premier;
	while (actuel != NULL)
	{
		ft_putstr(actuel->nombre);
		actuel = actuel->suivant;
	}

	ft_putstr("NULL\n");
}

/******************************************************************************/
/*********************************MAIN*****************************************/
/******************************************************************************/

int	main()
{
	Liste *maListe = initialisation();

	insertion(maListe, 4);
	insertion(maListe, 8);
	insertion(maListe, 15);
	suppression(maListe);

	return (0);
}
