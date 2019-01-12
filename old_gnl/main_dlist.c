/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cghanime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:15:37 by cghanime          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:45 by cghanime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	/*if (is_empty_dlist(mylist))
		printf("Elle est vide.\n");
	else
		printf("Elle contient des elements.\n");*/

	DList	mylist = new_dlist();
	printf("Taille de la DListe : %d\n", dlist_length(mylist));
	print_dlist(mylist);
	printf("\n**********************************************\n");
	mylist = insert_next_dlist(mylist, 14);
	printf("Taille de la DListe : %d\n", dlist_length(mylist));
	print_dlist(mylist);
	printf("\n**********************************************\n");
	mylist = insert_next_dlist(mylist, 6);
	mylist = insert_back_dlist(mylist, 23);
	printf("Taille de la DListe : %d\n", dlist_length(mylist));
	print_dlist(mylist);
	printf("\n**********************************************\n");
	/*mylist = delete_back_dlist(mylist);
	mylist = delete_next_dlist(mylist);
	printf("Taille de la DListe : %d\n", dlist_length(mylist));
	print_dlist(mylist);
	printf("\n**********************************************\n");
	mylist = delete_back_dlist(mylist);*/
	mylist = clear_dlist(mylist);
	printf("Taille de la DListe : %d\n", dlist_length(mylist));
	print_dlist(mylist);
	printf("\n**********************************************\n");
	return (0);
}
