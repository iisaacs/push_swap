/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:35:31 by iisaacs           #+#    #+#             */
/*   Updated: 2019/09/19 22:31:04 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotate stack (rot or rev_rot) depending on the specified number(n)
*/
void	 spec_rot_dec(t_nlist	**s_a, t_nlist	**s_b, int	*cc, int	n)
{
	t_nlist *node;
	int len;
	int i;

	node = (*s_b);
	len = list_len((*s_a));
	i = 0;
	while (node && i < len/2)
	{
		if (node->norm == n)
		{
			while ((*s_b)->norm != n)
				write(1, rot(s_a, s_b, "rb\n", cc), 3);
		}
		node = node->next;
		i++;
	}
	while ((*s_b)->norm != n)
		write(1, rev_rot(s_a, s_b, "rrb\n", cc), 3);
}

/*
** Push range(rng) to stack b in any order.
*/
void	push_rng_sb(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng)
{
	printf("here1");
	int t;
	int len;

	len = rng[2];
	t = (len <= 21) ? rng[0] : 20;
	if ((len % 2 != 0) && (len <= 21))
		t++;
	if (rng[0] == 0)
		t = rng[1];
	while (t)
	{
		while(!((*s_a)->norm > rng[0] && (*s_a)->norm <= rng[1]))
			rot_decider(s_a, s_b, cc, rng);
		write(1, push(s_a, s_b, "pb\n", cc), 3);
		t--;
	}
}

/*
** Push numbers in stack_b to stack_a in decending order and rotate to new group
** if min range is 0, push in ascending order.
*/

void	push_num_dec(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng)
{
	int n;
	int c;

	n = rng[1];
	c = 0;
	while (n > rng[0])
	{
		spec_rot_dec(s_a, s_b, cc, n);
		write(1, push(s_a, s_b, "pa\n", cc), 3);
		n--;
		c++;
	}
	while (c && rng[0] != 0)
	{
		write(1, rot(s_a, s_b, "ra\n", cc), 3);
		c--;
	}
}

/*
** modify range(rng)
*/

void	mod_rng(int *rng)
{
	int len;
	int tmp;

	len = rng[2];
	tmp = rng[0];
	rng[1] = rng[0];
	if (tmp >= 20)
		rng[0] = tmp - 20;
	rng[0] = tmp - tmp;
}

