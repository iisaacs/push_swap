#include "push_swap.h"

void    push_upd_grp(t_nlist **s_a, t_nlist **s_b, int *cc, int *grp)
{
    t_nlist *head_a;
    t_nlist *head_b;
    int times;

    head_a = (*s_a);
    head_b = (*s_b);
    times = grp[1];
    while (times)
    {
        if ((*s_a)->norm >= grp[0] && (*s_a)->norm <= grp[1])
        {
            if ((*s_a)->norm != grp[0])
            {
                sleep(1);
                write(1, push(s_a, s_b, "pb\n", cc), 3);
            }
            // else
            //     write(1, rot(s_a, s_b, "ra\n", cc), 3);
            times--;
        }
        else
        {
            sleep(1);
            write(1, rot(s_a, s_b, "ra\n", cc), 3);
        }
    }
}

void push_back_grp(t_nlist **s_a, t_nlist **s_b, int *cc, int *grp)
{
    int to_p = grp[1];
    printf("_____to_push:%i\n", grp[1]);

    while ((*s_b))
    {
        if ((*s_b)->norm != to_p)
        {
            sleep(1);
            write(1, rot(s_a, s_b, "rb\n", cc), 3);
        }
        else
        {
            sleep(1);
            write(1, push(s_a, s_b, "pa\n", cc), 3);
            to_p--;
        }
    }
}

/*
** Rotate stack (rot or rev_rot) depending on the specified number(n)
*/
void	 spec_rot_dec(t_nlist	**s_a, t_nlist	**s_b, int	*cc, int	n)
{
	t_nlist *node:

	node = (*s_a);
	while (node)
	{
		if (node->norm == n)
			write(1, rot(s_a, s_b, "rb\n", cc), 3);
		node = node->next;
	}
	write(1, rev_rot(s_a, s_b, "rrb\n", cc), 3);
	return (0);
}
