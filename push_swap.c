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

/*
** General sorting algorithm for numbers 5 and above.
** Push numbers in range to stack_b.
** Push numbers back in decending order.
** Modify the range and repeat untill list is sorted.
*/
void gen_algo(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng)
{
	print_list((*s_a), 1);
	print_list((*s_b), 1);
	int len;
	int t;

	len = list_len((*s_a));
	rng[2] = len;
	rng[1] = len;
	rng[0] = (len <= (RNG + 1)) ? len/2: len - RNG;

	//Get numbers close to each other not sorted
	//almost_sort(s_a, s_b, cc, rng);
	//mod_rng(rng);

	while (!is_list_sort((*s_a), (*s_b), 0))
	{
		push_rng_sb(s_a, s_b, cc, rng);
		push_num_dec(s_a, s_b, cc, rng);
		mod_rng(rng);
	}
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
	int	rng[3];

	cc = 0;
	head_b = NULL;
	if (ac > 1)
		get_int_list(&arga[1], &head_a, &ac);
	else
		return (0);
	if (is_list_sort(head_a, head_b, 0))
		return (0);
	if (ac <= 3)
		algo_3(&head_a, &head_b, &cc);
	else if (ac <= 5)
		algo_4_5(&head_a, &head_b, &cc, ac);
	else
	 	gen_algo(&head_a, &head_b, &cc, rng);
	return (0);
}
