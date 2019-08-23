/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:23:56 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/23 10:57:43 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_nlist
{
	int				n;
	struct s_nlist	*next;
}					t_nlist;

void				error(void);
void				get_int_list(char **a, t_nlist **b, int ac);

t_nlist				*new_nlist(int n);
void				add_nlist(t_nlist	**a, t_nlist *b, unsigned int m);
void				print_list(t_nlist *a, int i);
int					is_list_sort(t_nlist *a, t_nlist *b);
int					is_dup_list(t_nlist **a);

void				swap(t_nlist **a, t_nlist **b, char *cmd);
void				push(t_nlist **a, t_nlist **b, char *cmd);
void				rot(t_nlist **a, t_nlist **b, char *cmd);
void				rev_rot(t_nlist **a, t_nlist **b, char *cmd);

#endif
