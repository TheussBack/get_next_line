/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:24:14 by hrobin            #+#    #+#             */
/*   Updated: 2022/11/22 16:54:14 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rest_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!rest_str)
	{
		rest_str = (char *)malloc(1 * sizeof(char));
		rest_str[0] = '\0';
	}
	if (!rest_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(rest_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (rest_str)
		while (rest_str[++i] != '\0')
	str[i] = rest_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(rest_str) + ft_strlen(buff)] = '\0';
	free(rest_str);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
