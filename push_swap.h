/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 17:23:56 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/22 16:36:02 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define ERROR 1

typedef struct		s_nlist
{
	int				n;
	struct s_nlist	*next;
}					t_nlist;

t_nlist				*new_nlist(int );
void				add_nlist(t_nlist	**, t_nlist *, unsigned int);
void				print_list(t_nlist *, int);
int					is_list_sort(t_nlist *, t_nlist *);
int					is_dup_list(t_nlist **);

void				swap(t_nlist **, t_nlist **, char *);
void				push(t_nlist **, t_nlist **, char *);
void				rot(t_nlist **, t_nlist **, char *);
void				rev_rot(t_nlist **, t_nlist **, char *);

#endif
