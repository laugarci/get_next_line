/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:04 by laugarci          #+#    #+#             */
/*   Updated: 2022/12/06 18:16:32 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"
#include <stdio.h>

char	*ft_free(char **pt)
{
	free(*pt);
	pt = NULL;
	return (NULL);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buf;
	int		rdbytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{	
		ft_free(&str);
		return (NULL);
	}
	rdbytes = 1;
	while(!ft_strchr(str, '\n') && rdbytes != 0)
	{
		rdbytes = read(fd, buf, BUFFER_SIZE);
		if (rdbytes == -1)
		{
			free(ft_free(&str));
			return (NULL);
		}
		buf[rdbytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_find_line(str);
	str = ft_new_line(str);
	if (!line)
	{
		ft_free(&str);
		return (NULL);	
	}
	return (line);
}
/*
int main(void)
{
	int	fd;

	fd = open("./hola", O_RDONLY);
	get_next_line(fd);
	return (0);
}*/
