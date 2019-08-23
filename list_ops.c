/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:35:31 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/23 10:43:49 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Creates a new node with next to NULL,
** and n assigned to node's n.
*/

t_nlist	*new_nlist(int n)
{
	t_nlist	*node;

	if (!(node = (t_nlist*)malloc(sizeof(t_nlist))))
		return (NULL);
	node->next = NULL;
	node->n = n;
	return (node);
}

/*
** Add existing node to the list
** mode 1: adds node to end of list
** mode 2: adds node to beginnig of list (it's actually any number but 1)
*/

void	add_nlist(t_nlist **head, t_nlist *node, unsigned int mode)
{
	t_nlist *last;

	if (!(*head))
	{
		(*head) = node;
		return ;
	}
	if (mode == 1)
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	else
	{
		node->next = (*head);
		(*head) = node;
	}
}

/*
** Prints numbers in list
** if list empty print 'EMPTY'
*/

void	print_list(t_nlist *a, int n)
{
	t_nlist *temp;

	temp = (a);
	printf("Stack %d:\n", n);
	if (!temp)
	{
		printf("EMPTY\n");
		printf("----------------\n");
		return ;
	}
	while (temp->next)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	printf("%d\n", temp->n);
	printf("----------------\n");
}

/*
** Checks if there are any duplicate numbers
** in the list. If there is return TRUE, else return FALSE
*/

int		is_dup_list(t_nlist **a)
{
	t_nlist *node;
	t_nlist *head;

	if (!(*a))
		return (1);
	node = (*a);
	while (node)
	{
		head = node->next;
		while (head)
		{
			if (node->n == head->n)
				return (1);
			head = head->next;
		}
		node = node->next;
	}
	return (0);
}

/*
** Checks if list is sorted.
** If it is print 'OK' to stdout, return (1)
** else return (0)
*/

int		is_list_sort(t_nlist *a, t_nlist *b)
{
	t_nlist *node;
	t_nlist *temp;

	if (b)
		return (0);
	temp = a;
	node = temp->next;
	while (node)
	{
		if (temp->n > node->n)
			return (0);
		temp = temp->next;
		node = temp->next;
	}
	write(1, "OK\n", 3);
	return (1);
}
