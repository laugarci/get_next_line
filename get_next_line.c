/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:04 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/30 16:30:16 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

char	*ft_read_str(int fd, char *str)
{
	char	*buf;
	int		rd;
	
	rd = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while(!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*str;	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_find_line(str); 
	str = ft_new_line(str); 
	return (line);
}

int main(void)
{
	int	fd;

	fd = open("./hola", O_RDONLY);
	get_next_line(fd);
	return (0);
}
