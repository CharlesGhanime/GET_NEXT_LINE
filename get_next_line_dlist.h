/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_listes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:54:02 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/06 20:42:37 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 10

/******************************************************************************/
/************************DEFINITION D'UN BOOLEEN*******************************/
/******************************************************************************/

typedef enum	BOOLEAN
{
	FALSE,
	TRUE
}				BOOL;

/******************************************************************************/
/*******************DEFINITION D'UN MAILLON DE lA DLISTE***********************/
/******************************************************************************/

typedef struct	DListNode
{
	int buffer;
	struct DListNode	*back;
	struct DListNode	*next;
}				DListNode;

/******************************************************************************/
/************************DEFINITION D'UNE DLISTE*******************************/
/******************************************************************************/

typedef struct	DList
{
	int length;
	struct DListNode *begin;
	struct DListNode *end;
}				*DList;

/******************************************************************************/
/******************************PROTOTYPES**************************************/
/******************************************************************************/

DList	new_dlist(void);
BOOL	is_empty_dlist(DList li);
int		dlist_length(DList li);
int		dlist_first(DList li);
int		dlist_last(DList li);
void	print_dlist(DList li);
DList	insert_back_dlist(DList li, int x);
DList	insert_next_dlist(DList li, int x);
DList	delete_back_dlist(DList li);
DList	delete_next_dlist(DList li);
DList	clear_dlist(DList li);

int		get_next_line(const int fd, char **line);

# endif
