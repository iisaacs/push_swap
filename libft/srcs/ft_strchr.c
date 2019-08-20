/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 08:38:49 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/06 14:12:30 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if ((char)c == (char)str[i])
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
