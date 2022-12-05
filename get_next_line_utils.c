/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:18:51 by laugarci          #+#    #+#             */
/*   Updated: 2022/12/05 18:04:44 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return ((size_t)i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	
	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*s;
	size_t	i;
	size_t	j;
	int		tlen;
	
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	tlen = ft_strlen(str) + ft_strlen(buf);
	s = malloc(sizeof(char) * (tlen + 1));
	if (s == NULL)
		return(NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			s[i] = str[i];
	while (buf[j] != '\0')
		s[i++] = buf[j++];
	s[tlen] = '\0';
	free(str);
	return (s);
}

char	*ft_find_line(char *str)
{
	int i;
	char *s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (str);
}

char	*ft_new_line(char *str)
{
	int	i;
	int j;
	char *s;

	i = 0;
//	printf("%s", str);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
//	printf("%s\n", str);
	while (str[i])
		s[j++] = str[i++];
//	printf("%s\n", str);
	s[j] = '\0';
//	free(str);
	ft_free(&str);
	if (!s)
		return (NULL);
//	printf("%s\n", s);
	return (s);
}
