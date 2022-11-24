/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:51:57 by hrobin            #+#    #+#             */
/*   Updated: 2022/11/22 16:59:00 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_keeprest_str(int fd, char *rest_str)
{
	char	*buff;
	int		nb_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);	//je sais pas pour le +1 (pour le \0 jpense)
	if (!buff)
		return (NULL);
	nb_bytes = 1;
	while (!ft_strchr(rest_str, '\n') && nb_bytes != 0) // tant que il n'y a pas de \n etr que le retour de read est pas -1
	{
		nb_bytes = read(fd, buff, BUFFER_SIZE);
		if (nb_bytes == -1) //Si read renvoi -1 c'est quand il y a une erreur 
		{
			free(buff);
			return (NULL);
		}
		buff[nb_bytes] = '\0'; // ici
		rest_str = ft_strjoin(rest_str, buff); // concat au cas ou rest_str ya qqchose
	}
	free (buff);
	return (rest_str);
}

char	*ft_findline(char *rest_str) // verif et renvoi jusquau '\n'
{
	int	i;
	char	*newline;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] != '\n' && rest_str[i])
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 1)); // je sais toujours pas pour le \0
	if (!newline)
		return (NULL);
	i = 0;
	while (rest_str[i] != '\n' && rest_str[i])
	{
		newline[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n') // recup le \n vu qu'on veut le renvoyer
	{
		newline[i] = rest_str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*ft_newstr(char *rest_str) // recup le reste pour une nouvelle chaine 
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (rest_str[i] != '\n' && rest_str[i])
		i++;
	if (!rest_str[i])
	{
		free(rest_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	j = 0;
	i++;
	while (rest_str[i])
		str[j++] = rest_str[i++]; // on recup si il y a l'apres le \n
	str[j] = '\0';
	free (rest_str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rest_str;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest_str = ft_keeprest_str(fd, rest_str); // rest_str recup le buff
	if (!rest_str)
		return (NULL);
	line = ft_findline(rest_str); // on extrait la ligne avec le \n
	rest_str = ft_newstr(rest_str); // on recup si ya qqchose apres le /n
	return (line);
}
