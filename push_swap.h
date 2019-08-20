/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:23:56 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/20 16:50:29 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# define ERROR 1

typedef struct		s_nlist
{
	int				n;
	struct s_nlist	*next;
}					t_nlist;

t_nlist				*new_nlist(int );
void				after_nlist(t_nlist	**, t_nlist *);
void				push_nlist(t_nlist **, t_nlist *);
void				pop_nlist(t_nlist **);
void				print_list(t_nlist *, int);

void				swap(t_nlist **, t_nlist **, char *);
void				push(t_nlist **, t_nlist **, char *);
void				rot(t_nlist **, t_nlist **, char *);
void				rev_rot(t_nlist **, t_nlist **, char *);
int					is_dup_list(t_nlist **);
int					is_list_sort(t_nlist **, t_nlist **);

#endif
