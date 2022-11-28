/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:41:51 by rserafim          #+#    #+#             */
/*   Updated: 2022/05/17 10:45:05 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	init_check(int fd, t_read *strct)
{
	strct->pos = 0;
	strct->max = read(fd, strct->str, BUFFER_SIZE);
	strct->fd = fd;
	if (strct->max <= 0)
		return (0);
	else
		return (1);
}

char	read_check(t_read *strct)
{
	char	result;

	if (strct-> pos >= strct->max)
	{
		strct->max = read(strct->fd, strct->str, BUFFER_SIZE);
		strct->pos = 0;
		if (strct->max <= 0)
			return (0);
	}
	result = strct->str[strct->pos];
	strct->pos++;
	return (result);
}
