/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:17:12 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/22 16:46:56 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

/*
** create a list of integers from a string array
** and prints the list to stdout.
*/

void	get_int_list(char **str_ar, t_nlist **head, int ac)
{
	int		i;
	t_nlist	*n_node;

	i = 0;
	if (ac == 2)
		str_ar = ft_strsplit(str_ar[0], ' ');
	while (str_ar[i])
	{
		if (ft_strcmp(ft_itoa(ft_atoi(str_ar[i])), str_ar[i]) == 0)
		{
			n_node = new_nlist(ft_atoi(str_ar[i]));
			add_nlist(head, n_node, 1);
		}
		else
			error();
		i++;
	}
	if (is_dup_list(head))
		error();
	print_list((*head), 1);
	return ;
}

/*
** Checks if str is a valid command if it
** is run the cmd on desired stack, return (1)
** else return (0);
*/

int		is_cmd_exe(char *str, t_nlist **head_a, t_nlist **head_b)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
			|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
			|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
			|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
			|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
			|| ft_strcmp(str, "rrr") == 0)
	{
		if (ft_strlen(str) == 2)
		{
			if (str[0] == 's')
				swap(head_a, head_b, str);
			else if (str[0] == 'p')
				push(head_a, head_b, str);
			else if (str[0] == 'r')
				rot(head_a, head_b, str);
		}
		rev_rot(head_a, head_b, str);
		return (1);
	}
	error();
	return (0);
}

/*
** Checker Program
*/

int		main(int ac, char **arg_a)
{
	t_nlist *head_a;
	t_nlist *head_b;
	char	*line;

	head_a = NULL;
	head_b = NULL;
	if (ac > 1)
		get_int_list(&arg_a[1], &head_a, ac);
	else
		return (0);
	print_list(head_b, 2);
	if (is_list_sort(head_a, head_b))
		return (1);
	while (get_next_line(0, &line) > 0)
	{
		if (is_cmd_exe(line, &head_a, &head_b))
		{
			print_list(head_a, 1);
			print_list(head_b, 2);
			if (is_list_sort(head_a, head_b))
				return (1);
		}
	}
	write(1, "KO\n", 3);
	return (0);
}
