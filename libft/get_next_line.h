/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:38:27 by rserafim          #+#    #+#             */
/*   Updated: 2022/05/17 10:41:08 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef     BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include "libft.h"

//structure = regroupement de données
typedef struct t_read
{
	int		fd;
	int		max;
	int		pos;
	char	str[BUFFER_SIZE];
}	t_read;

int		ft_strlen_int(char *str);
char	*ft_strjoin_char(char *s1, char chara);
char	*get_next_line(int fd);
int		init_check(int fd, t_read *strct);
char	read_check(t_read *strct);
#endif
