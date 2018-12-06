/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_listes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:52:34 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/06 20:41:21 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/******************************************************************************/
/********************************NEW_LIST**************************************/
/******************************************************************************/

DList	new_dlist(void)
{
	return (NULL);
}

/******************************************************************************/
/******************************IS_EMPTY_LIST***********************************/
/******************************************************************************/

BOOL	is_empty_dlist(DList li)
{
	if (li == NULL)
		return (TRUE);
	return (FALSE);
}

/******************************************************************************/
/*******************************DLIST_LENGTH***********************************/
/******************************************************************************/

int		dlist_length(DList li)
{
	if (is_empty_dlist(li))
		return (0);
	return (li->length);
}

/******************************************************************************/
/********************************DLIST_FIRST***********************************/
/******************************************************************************/

int		dlist_first(DList li)
{
	if (is_empty_dlist(li))
		return (-1);
	return (li->begin->buffer);
}

/******************************************************************************/
/*********************************DLIST_LAST***********************************/
/******************************************************************************/

int		dlist_last(DList li)
{
	if (is_empty_dlist(li))
		return (-1);
	return (li->end->buffer);
}

/******************************************************************************/
/********************************PRINT_DLIST***********************************/
/******************************************************************************/

void	print_dlist(DList li)
{
	if (is_empty_dlist(li))
	{
		printf("RaF, la liste est vide\n");
		return;
	}
	DListNode *temp = li->begin;
	while (temp != NULL)
	{
		printf("[%d]", temp->buffer);
		temp = temp->next;
	}
	printf("\n");
}

/******************************************************************************/
/***************************INSERT_BACK_LIST***********************************/
/******************************************************************************/

DList	insert_back_dlist(DList li, int x)
{
	DListNode *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->buffer = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(li))
	{
		if (!(li = malloc(sizeof(*li))))
			return (NULL);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->end->next = element;
		element->next = li->end;
		li->end = element;
	}
	li->length++;
	return (li);
}

/******************************************************************************/
/***************************INSERT_NEXT_LIST***********************************/
/******************************************************************************/

DList	insert_next_dlist(DList li, int x)
{
	DListNode *element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->buffer = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(li))
	{
		if (!(li = malloc(sizeof(*li))))
			return (NULL);
		li->length = 0;
		li->begin = element;
		li->end = element;
	}
	else
	{
		li->begin->back = element;
		element->next = li->end;
		li->begin  = element;
	}
	li->length++;
	return (li);
}

/******************************************************************************/
/***************************DELETE_BACK_LIST***********************************/
/******************************************************************************/

DList	delete_back_dlist(DList li)
{
	if (is_empty_dlist(li))
	{
		printf("DList deja vide, rien a supprimer\n");
		return (new_dlist());
	}
	if (li->begin == li->end)
	{
		free(li);
		li = NULL;
		return (new_dlist());
	}
	DListNode *temp = li->end;
	li->end = li->end->back;
	li->end->next = NULL;
	temp->next = NULL;
	temp->back = NULL;
	free(temp);
	temp = NULL;
	li->length--;
	return(li);
}

/******************************************************************************/
/***************************DELETE_NEXT_LIST***********************************/
/******************************************************************************/

DList	delete_next_dlist(DList li)
{
	if (is_empty_dlist(li))
	{
		printf("DList deja vide, rien a supprimer\n");
		return (new_dlist());
	}
	if (li->begin == li->end)
	{
		free(li);
		li = NULL;
		return (new_dlist());
	}
	DListNode *temp = li->begin;
	li->begin = li->begin->next;
	li->begin->back = NULL;
	temp->next = NULL;
	temp->back = NULL;
	free(temp);
	temp = NULL;
	li->length--;
	return(li);
}

/******************************************************************************/
/***************************DELETE_ALL_LIST***********************************/
/******************************************************************************/

DList	clear_dlist(DList li)
{
	while (!is_empty_dlist(li))
		li = delete_next_dlist(li);
	return (new_dlist());
}

