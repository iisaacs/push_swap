#include "push_swap.h"

void	normalizer(t_nlist	*list, int	ac)
{
	t_nlist *temp;
	t_nlist *node;

	node = temp = list;
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

void	push_back_rot(t_nlist **s_a, t_nlist **s_b, int *cc, int max_int)
{
	int times = max_int - 3;
	if ((*s_b)->norm != max_int)
		write(1, rot(s_a, s_b, "rb\n", cc), 3);
	while (times--)
		write(1, push(s_a, s_b, "pa\n", cc), 3);
	times = max_int - 3;
	while (times--)
		write(1, rot(s_a, s_b, "ra\n", cc), 3);
}