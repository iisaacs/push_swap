/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:17:12 by iisaacs           #+#    #+#             */
/*   Updated: 2019/09/16 02:00:50 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if str is a valid command if it
** is run the cmd on desired stack, return (1)
** else return (0);
*/

int		is_cmd_exe(char *str, t_nlist **head_a, t_nlist **head_b)
{
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 || 
	    ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "pa") == 0 ||
	    ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "ra") == 0 ||
	    ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0 ||
	    ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rrb") == 0 ||
	    ft_strcmp(str, "rrr") == 0)
	{
		if (ft_strlen(str) == 2)
		{
			if (str[0] == 's')
				swap(head_a, head_b, str, NULL);
			else if (str[0] == 'p')
				push(head_a, head_b, str, NULL);
			else if (str[0] == 'r')
				rot(head_a, head_b, str, NULL);
		}
		else
			rev_rot(head_a, head_b, str, NULL);
		return (1);
	}
	ERROR;
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
		get_int_list(&arg_a[1], &head_a, &ac);
	else 
		return (0);
	while (get_next_line(0, &line) > 0)
		is_cmd_exe(line, &head_a, &head_b);
	if (is_list_sort(head_a, head_b, 1))
		return (1);
	write(1, "\e[0;31mKO\n", 10);
	return (0);
}
