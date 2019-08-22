/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:36:55 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/22 16:31:31 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
 * Swap command, swaps first and second number in list
 */
void	swap(t_nlist **s_a, t_nlist **s_b, char *cmd)
{
	t_nlist	*temp;

	if (cmd[1] == 'a' || cmd[1] == 's')
	{
		if (!(*s_a) || (!(*s_a)->next))
			return ;
		temp = (*s_a);
		(*s_a) = (*s_a)->next;
		temp->next = (*s_a)->next;
		(*s_a)->next = temp;
	}
	if (cmd[1] == 'b' || cmd[1] == 's')
	{
		if (!(*s_b) || (!(*s_b)->next))
			return ;
		temp = (*s_b);
		(*s_b) = (*s_b)->next;
		temp->next = (*s_b)->next;
		(*s_b)->next = temp;
	}
}

/*
 * Push first number from 
 * stack to another stack
 */
void	push(t_nlist **s_a, t_nlist **s_b, char *cmd)
{
	t_nlist	*tmp;
	t_nlist **temp_a;

	if (cmd[1] == 'b')
	{
		temp_a = s_a;
		s_a = s_b;
		s_b = temp_a;
	}
	if (!(*s_b))
		return ;
	tmp = (*s_b);
	(*s_b) = (*s_b)->next;
	tmp->next = NULL;
	add_nlist(s_a, tmp, 2);
}

/*
 * Rotate list by 1, first number becomes last
 * and second number becomes first.
 */
void	rot(t_nlist **s_a, t_nlist **s_b, char *cmd)
{
	t_nlist *temp;
	t_nlist *head;

	if (cmd[1] == 'a' || cmd[1] == 'r')
	{
		if (!(*s_a) || !(*s_a)->next)
			return ;
		temp = (*s_a);
		(*s_a) = (*s_a)->next;
		head = (*s_a);
		temp->next = NULL;
		while (head->next)
			head = head->next;
		head->next = temp;
	}
	if (cmd[1] == 'b'|| cmd[1] == 'r')
	{
		if (!(*s_b) || !(*s_b)->next)
			return ;
		temp = (*s_b);
		(*s_b) = (*s_b)->next;
		head = (*s_b);
		temp->next = NULL;
		while (head->next)
			head = head->next;
		head->next = temp;
	}
}

/*
 * The inverse to rot, last number becomes first.
 */
void	rev_rot(t_nlist **s_a, t_nlist **s_b, char *cmd)
{
	t_nlist *temp;
	t_nlist *head;

	if (cmd[2] == 'a' || cmd[2] == 'r')
	{
		if (!(*s_a) || !(*s_a)->next)
			return ;
		head = (*s_a);
		while ((*s_a)->next->next)
			(*s_a) = (*s_a)->next;
		temp = (*s_a)->next;
		(*s_a)->next = NULL;
		temp->next = head;
		(*s_a) = temp;
	}
	if (cmd[2] == 'a' || cmd[2] == 'r')
	{
		if (!(*s_b) || !(*s_b)->next)
			return ;
		head = (*s_b);
		while ((*s_b)->next->next)
			(*s_b) = (*s_b)->next;
		temp = (*s_b)->next;
		(*s_b)->next = NULL;
		temp->next = head;
		(*s_b) = temp;
	}
}


