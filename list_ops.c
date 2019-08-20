/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:35:31 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/20 16:59:49 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * Create a new node with next to NULL,
 * and n assigned to node's n.
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
 * Add existing node to the end of list
 */
void	after_nlist(t_nlist **head, t_nlist *node)
{
	t_nlist *last;

	last = *head;
	if (!(*head))
	{
		*head = node;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = node;
}

/*
 * Add existing node to beginning of list
 */
void	push_nlist(t_nlist **head, t_nlist *node)
{

	if (!(*head))
	{
		(*head) = (node);
		return ;
	}
	(node)->next = (*head);
	(*head) = (node);
}

/*
 * Print numbers in lists
 */
void	print_list(t_nlist *a, int n)
{
	t_nlist *temp;

	temp = (a);
	if (!temp)
		return ;
	printf("Stack %d:\n", n);
	while (temp->next)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	printf("%d\n", temp->n);
}

/*
 * Check if there is duplicates numbers
 * in list
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
