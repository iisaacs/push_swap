/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:58:01 by iisaacs           #+#    #+#             */
/*   Updated: 2019/09/12 12:39:43 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorting algorithm for 3 numbers
*/

void	algo_3(t_nlist	**s_a, t_nlist  **s_b, int	*cc)
{
	while (!is_list_sort((*s_a), NULL, 0))
	{
		if ((*s_a)->norm == 2 && (*s_a)->next->norm == 1)
			write(1, swap(s_a, s_b, "sa\n", cc), 3);
		if ((*s_a)->norm == 3 || (*s_a)->norm == 2)
			write(1, rot(s_a, s_b, "ra\n", cc), 3);
		else if ((*s_a)->norm == 1 && (*s_a)->next->norm == 3)
			write(1, rev_rot(s_a, s_b, "rra\n", cc), 4);
	}
}

/*
** Sorting algorithm for 4 and 5 numbers.
*/
void	algo_4_5(t_nlist   **s_a, t_nlist	**s_b, int	*cc, int	ac)
{
	int t;
	
	t = (ac == 5) ? 5: 4;
	while (t > 3)
	{
		while ((*s_a)->norm != t)
		{
			if ((*s_a)->norm != t && (*s_a)->next->norm != t)
				write(1, rev_rot(s_a, s_b, "rra\n", cc), 4);
			else
				write(1, rot(s_a, s_b, "ra\n", cc), 3);
		}
		write(1, push(s_a, s_b, "pb\n", cc), 3);
		t--;
	}
	algo_3(s_a, s_b, cc);
	t = (ac == 5) ? 5: 4;
	while (t > 3)
	{
		write(1, push(s_a, s_b, "pa\n", cc), 3);
		write(1, rot(s_a, s_b, "ra\n", cc), 3);
		t--;
	}
}

void gen_algo(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng)
{
	int len;
	int t;

	len = list_len((*s_a));
	rng[1] = len;
	rng[0] = (len <= 21) ? len/2: len - 20 ;
	t = (len <= 21) ? rng[0] : 20 ;
	if ((len % 2) != 0 && (len <= 21))
		t++;
	//printf("min: %d, max: %d, t: %d\n", rng[0], rng[1], t);

	while (t)
	{
		//printf("norm: %d", (*s_a)->norm);
		while (!((*s_a)->norm > rng[0] && (*s_a)->norm <= rng[1]))
			rot_decider(s_a, s_b, cc, rng);
		write(1, push(s_a, s_b, "pb\n", cc), 3);
		t--;
		//change times to loop depending on the length of stack
	}
	//push_dec(s_a, s_b, cc);
}

/*
** Push_swap program
*/

int		main(int	ac, char	**arga)
{
	t_nlist *head_a;
	t_nlist *head_b;
	char	*line;
	int	cc;
	int	rng[2];

	cc = 0;
	head_b = NULL;
	if (ac > 1)
		get_int_list(&arga[1], &head_a, &ac);
	else
		return (0);
	if (ac <= 3)
		algo_3(&head_a, &head_b, &cc);
	else if (ac <= 5)
		algo_4_5(&head_a, &head_b, &cc, ac);
	 else
	 	gen_algo(&head_a, &head_b, &cc, rng);
	printf("cc: %d\n", cc);
	print_list(head_a, 1);
	return (0);
}
