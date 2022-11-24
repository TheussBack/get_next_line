/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:06:59 by hrobin            #+#    #+#             */
/*   Updated: 2022/11/22 16:46:45 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_keeprest_str(int fd, char *rest_str);
char 	*ft_findline(char *rest_str);
char	*ft_newstr(char *rest_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *rest_str, char *buff);
size_t	ft_strlen(char *s);

#endif
