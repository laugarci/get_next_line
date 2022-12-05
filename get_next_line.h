/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:11:34 by laugarci          #+#    #+#             */
/*   Updated: 2022/12/05 14:01:29 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
char	*ft_free(char **pt);
size_t	ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buf);
char	*ft_find_line(char *str);
char	*ft_new_line(char *str);

#endif
