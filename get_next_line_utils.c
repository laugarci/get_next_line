/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:18:51 by laugarci          #+#    #+#             */
/*   Updated: 2022/11/30 16:30:13 by laugarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (c == '\0')
		j = ft_strlen(s);
		return ((char *)&s[j]);
	while(s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buf)
{
	char	*s;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = -1;
	j = 0;
	len1 = (ft_strlen(str));
	len2 = (ft_strlen(buf));
	if (!str || !buf)
		return (0);
	s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (0);
	if (str)
	{
		while (str[i])
			s[i] = str[i];
		i++;
	}
	while (buf[j])
		s[i++] = buf[j++];
	s[i] = '\0';
	free(str);
	return (s);
}

char	*ft_find_line(char *str)
{
	int i;
	char *s;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
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
	str[i] = '\0';
	return (str);
}

char	*ft_new_line(char *str)
{
	int	i;
	char *s;
	size_t len;
	int j;

	j = 0;
	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i++;
	while (s[i])
	{
		s[j] = str[i];
		j++;
		i++;
	}
	s[j] = '\0';
	free(str);
	return (s);
}
