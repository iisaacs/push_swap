/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iisaacs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 09:20:34 by iisaacs           #+#    #+#             */
/*   Updated: 2019/08/19 09:49:18 by iisaacs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*cpy_nl(char **file, char **line)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	temp = (*file);
	if (ft_strlen(*file) == 0)
		return (NULL);
	while ((**file) && **file != '\n')
		(*file)++;
	len = (*file) - temp;
	*line = malloc((size_t)(len + 1));
	while (i < len)
	{
		(*line)[i] = temp[i];
		i++;
	}
	(*line)[i] = '\0';
	if (**file == '\n')
		(*file)++;
	if (**file == '\0')
		(*file) = NULL;
	return (*line);
}

char	*my_read(char *file, char *buff, const int fd)
{
	int		ret;
	char	*temp;

	ret = 1;
	temp = NULL;
	while (ft_strchr(file, '\n') == NULL && ret != 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		if (!(file))
			file = ft_strdup((const char*)buff);
		else
		{
			file = ft_strjoin(file, (const char*)buff);
			free(temp);
		}
		temp = (file);
	}
	return (file);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*all_files[65536];

	if (fd < 0 || !line || BUFF_SIZE < 0 || (read(fd, buff, 0) == -1))
		return (-1);
	*line = NULL;
	all_files[FREE_MEM] = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	all_files[fd] = my_read(all_files[fd], buff, fd);
	all_files[FREE_MEM] = all_files[fd];
	*line = cpy_nl(&all_files[fd], line);
	if ((!(*line) && ((ft_strlen(all_files[fd]) == 0) || !all_files[fd])))
	{
		free(all_files[FREE_MEM]);
		all_files[fd] = NULL;
		return (0);
	}
	return (1);
}
