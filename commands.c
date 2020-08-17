/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:36:55 by iisaacs           #+#    #+#             */
/*   Updated: 2019/09/19 18:37:55 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Swap command:
** swaps first and second link in list
*/

char	*swap(t_nlist **s_a, t_nlist **s_b, char *cmd, int *cc)
{
	t_nlist	*temp;

	if (cc)
		(*cc)++;
	if (cmd[1] == 'a' || cmd[1] == 's')
	{
		if (!(*s_a) || (!(*s_a)->next))
			return (NULL);
		temp = (*s_a);
		(*s_a) = (*s_a)->next;
		temp->next = (*s_a)->next;
		(*s_a)->next = temp;
	}
	if (cmd[1] == 'b' || cmd[1] == 's')
	{
		if (!(*s_b) || (!(*s_b)->next))
			return (NULL);;
		temp = (*s_b);
		(*s_b) = (*s_b)->next;
		temp->next = (*s_b)->next;
		(*s_b)->next = temp;
	}
	return (cmd);
}

/*
** Push command:
** add first link from
** stack to the top of second stack
*/

char	*push(t_nlist **s_a, t_nlist **s_b, char *cmd, int	*cc)
{
	t_nlist	*tmp;
	t_nlist **temp_a;

	if (cc)
		(*cc)++;
	if (cmd[1] == 'b')
	{
		temp_a = s_a;
		s_a = s_b;
		s_b = temp_a;
	}
	if (!(*s_b))
		return (NULL);
	tmp = (*s_b);
	(*s_b) = (*s_b)->next;
	tmp->next = NULL;
	add_nlist(s_a, tmp, 2);
	return (cmd);
}

/*
** Rotate command:
** Rotate list by 1, first number becomes last
** and second number becomes first.
*/

char	*rot(t_nlist **s_a, t_nlist **s_b, char *cmd, int	*cc)
{
	t_nlist *temp;
	t_nlist *head;
	int		times;

	if (cc)
		(*cc)++;
	times = (cmd[1] == 'r') ? 2 : 1;
	s_a = (cmd[1] == 'b') ? s_b : s_a;
	while (times)
	{
		if (!(*s_a) || !(*s_a)->next)
			return (cmd);
		temp = (*s_a);
		(*s_a) = (*s_a)->next;
		head = (*s_a);
		temp->next = NULL;
		while (head->next)
			head = head->next;
		head->next = temp;
		if (cmd[1] == 'r')
			s_a = s_b;
		times--;
	}
	return (cmd);
}

/*
** Reverse Rotate command:
** The inverse to rot, last number becomes first.
** and first becomes second.
*/

char	*rev_rot(t_nlist **s_a, t_nlist **s_b, char *cmd, int	*cc)
{
	t_nlist *temp;
	t_nlist *head;
	int		times;

	if (cc)
		(*cc)++;
	times = (cmd[2] == 'r') ? 2 : 1;
	s_a = (cmd[2] == 'b') ? s_b : s_a;
	while (times)
	{
		if (!(*s_a) || !(*s_a)->next)
			return (NULL);
		head = (*s_a);
		while ((*s_a)->next->next)
			(*s_a) = (*s_a)->next;
		temp = (*s_a)->next;
		(*s_a)->next = NULL;
		temp->next = head;
		(*s_a) = temp;
		if (cmd[2] == 'r')
			s_a = s_b;
		times--;
	}
	return (cmd);
}

/*
** Create a list of number from a string array
** and prints the list to stdout.
*/

void	get_int_list(char **str_ar, t_nlist **head, int *ac)
{
	int		i;
	t_nlist	*n_node;

	i = 0;
	if (*ac == 2)
		str_ar = ft_strsplit(str_ar[0], ' ');
	while (str_ar[i])
	{
		if (ft_strcmp(ft_itoa(ft_atoi(str_ar[i])), str_ar[i]) == 0)
		{
			n_node = new_nlist(ft_atoi(str_ar[i]));
			add_nlist(head, n_node, 1);
		}
		else
			ERROR;
		i++;
	}
	(*ac) = i;
	if (is_dup_list(head))
		ERROR;
	normalizer((*head), (*ac));
	return ;
}
