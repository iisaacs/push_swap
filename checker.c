/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:17:12 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/20 17:08:07 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	error()
{
	write(2, "Error\n", 6);
	exit(-1);
}

/*
 * create a list of integers from a string array
 */
void	get_int_list(char **str_ar, t_nlist **head, int ac)
{
	int i;
	t_nlist *n_node;

	i = 0;
	if (ac == 2)
		str_ar = ft_strsplit(str_ar[0], ' ');
	while (str_ar[i])
	{
		if (ft_strcmp(ft_itoa(ft_atoi(str_ar[i])), str_ar[i]) == 0)
		{
			n_node = new_nlist(ft_atoi(str_ar[i]));
			after_nlist(head, n_node);
		}
		else
			error();
		i++;
	}
	if (is_dup_list(head))
		error();
	return ; 
}

/*
 * Checks if str is a valid command if it is return (1)
 * else return (0);
 */
int		is_cmd(char *str)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
			|| ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0
			|| ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0
			|| ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0
			|| ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0
			|| ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

void	exe_cmd(t_nlist **head_a, t_nlist **head_b, char *line)
{
	if (ft_strlen(line) == 2)
	{
		if (line[0] == 's')
			swap(head_a, head_b, line);
		else if (line[0] == 'p')
			push(head_a, head_b, line);
		else if	(line[0] == 'r')
			rot(head_a, head_b, line);
	}
	rev_rot(head_a, head_b, line);
}

/*
 * Checker Program
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
	print_list(head_a, 1);
	printf("----------------\n");
	if (is_list_sort(&head_a, &head_b))
	{
		write (1, "OK\n", 3);
		return (1);
	}	
	while (get_next_line(0, &line) > 0)
	{
		if (is_cmd(line))
		{
			exe_cmd(&head_a, &head_b, line);
			print_list(head_a, 1);
			print_list(head_b, 2);
			printf("----------------\n");
			if (is_list_sort(&head_a, &head_b))
			{
				write (1, "OK\n", 3);
				return (1);
			}
		}
		else
			error();
	}
	write (1, "KO\n", 3);
	return (1);
}
