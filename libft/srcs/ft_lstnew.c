/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:10:06 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/19 10:31:13 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int n)
{
	t_list *new_ls;

	printf("here\n");
	if (!(new_ls = (t_list *)malloc(sizeof(new_ls) + 1)))
		return (NULL);
	new_ls->n = n;
	new_ls->next = NULL;
	return (new_ls);
}
