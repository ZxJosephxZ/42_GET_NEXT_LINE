/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpajuelo <jpajuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:51:20 by jpajuelo          #+#    #+#             */
/*   Updated: 2023/04/26 10:48:58 by jpajuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	c1;
	size_t	c2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	c1 = -1;
	c2 = 0;
	if (s1)
		while (s1[++c1] != '\0')
			s[c1] = s1[c1];
	while (s2[c2] != '\0')
		s[c1++] = s2[c2++];
	s[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (s);
}
