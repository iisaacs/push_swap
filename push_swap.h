/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:23:56 by iisaacs           #+#    #+#             */
/*   Updated: 2019/09/13 15:31:49 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define ERROR {write(2, "Error\n", 6); exit(-1);}

typedef struct		s_nlist
{
	int				n;
	int				norm;
	struct s_nlist	*next;
}					t_nlist;

void				get_int_list(char **a, t_nlist **b, int *ac);

t_nlist				*new_nlist(int n);
void				add_nlist(t_nlist	**a, t_nlist *b, unsigned int m);
int				is_list_sort(t_nlist *a, t_nlist *b, int m);
int				is_dup_list(t_nlist **a);

char				*swap(t_nlist **a, t_nlist **b, char *cmd, int	*cc);
char				*push(t_nlist **a, t_nlist **b, char *cmd, int	*cc);
char				*rot(t_nlist **a, t_nlist **b, char *cmd, int	*cc);
char				*rev_rot(t_nlist **a, t_nlist **b, char *cmd, int *cc);

int				list_ln(t_nlist *a);
void				normalizer(t_nlist	*list, int	ac);
int				list_len(t_nlist *list);
int				is_dup_list(t_nlist **head);
int				rot_decider(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng);

void				push_rng_sb(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng);
void				push_num_dec(t_nlist **s_a, t_nlist **s_b, int *cc, int *rng);
void				mod_rng(int *rng);

#endif
