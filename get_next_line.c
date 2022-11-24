/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:51:57 by hrobin            #+#    #+#             */
/*   Updated: 2022/11/24 08:45:02 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_keeprest_str(int fd, char *rest_str)
{
	char	*buff;
	int		nb_bytes;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!buff)
		return (NULL);
	nb_bytes = 1;
	while (!ft_strchr(rest_str, '\n') && nb_bytes != 0)
	{
		nb_bytes = read(fd, buff, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nb_bytes] = '\0';
		rest_str = ft_strjoin(rest_str, buff);
	}
	free (buff);
	return (rest_str);
}

char	*ft_findline(char *rest_str)
{
	int	i;
	char	*newline;

	i = 0;
	if (!rest_str[i])
		return (NULL);
	while (rest_str[i] != '\n' && rest_str[i])
		i++;
	newline = (char *)malloc(sizeof(char) * (i + 2));
	if (!newline)
		return (NULL);
	i = 0;
	while (rest_str[i] != '\n' && rest_str[i])
	{
		newline[i] = rest_str[i];
		i++;
	}
	if (rest_str[i] == '\n')
	{
		newline[i] = rest_str[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}

char	*ft_newstr(char *rest_str)
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(rest_str) - i + 1));
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
/*
int main()
{
     int fd; // file descriptor
     char *line; // ligne a lire

     fd = open("blabla.txt", O_RDONLY); // on ouvre notre fichier en read only
     while(1)
     {
         line = get_next_line(fd); // on lit la ligne de notre fichier ouvert et on la stock dans line
         if (line == NULL) // si line est null, on a atteint la fin du fichier car get_next_line renvoie NULL quand il n'y a plus rien a lire
         {
             free(line); // on libere la memoire allouee a line pour eviter les leaks car on aura plus aucunn moyen de la free si on le fait pas mtn
             break; // on sort de la boucle
         }
         else // si line n'est pas null, on a pas atteint la fin du fichier donc on affiche la ligne
         {
             printf("%s", line); // on affiche la ligne
             free(line); // on libere la memoire allouee a line pour eviter les leaks car on aura plus aucunn moyen de la free si on le fait pas mtn
         }
     }
     return (0);
 }
*/
