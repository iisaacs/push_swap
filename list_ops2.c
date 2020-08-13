#include "push_swap.h"

void	normalizer(t_nlist	*list, int	ac)
{
	t_nlist *temp;
	t_nlist *node;

	node = list;
	temp = list;
	while (node)
	{
		node->norm = ac;
		while (temp)
		{
			if (node->n < temp->n)
				(node->norm) = (node->norm) - 1;
			temp = temp->next;
		}
		temp = list;
		node = node->next;
	}
}

int		list_len(t_nlist	*list)
{
	int	count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

/*
** Takes list and an range(rng) of numbers to be pushed returns 1 
** to indicate rotate, and return (0) ro reverse rotate
*/

int	rot_decider(t_nlist **s_a, t_nlist **s_b,int *cc, int *rng)
{
	t_nlist *node;

	node = (*s_a);
	while (node)
	{
		if (node->norm > rng[0] && node->norm <= rng[1])
		{
			write(1, rot(s_a, s_b, "ra\n", cc), 3);
			return (1);
		}
		node = node->next;
	}
	write(1, rev_rot(s_a, s_b, "rra\n", cc), 3);
	return (0);
}
