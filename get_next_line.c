/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:08:04 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/20 14:30:14 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	buff[100];

	if (fd < 0 || buff < 0)
		return (NULL);
	read(fd, buff, 100);
	printf("%s\n", buff);
	return (0);
}

int main(void)
{
	int	fd;

	fd = open("./hola", O_RDONLY); //open(path(donde esta el archivo), permisos)
	get_next_line(fd);
	return (0);
}
