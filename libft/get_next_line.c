/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:50:48 by rserafim          #+#    #+#             */
/*   Updated: 2022/11/07 17:55:20 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_strlen_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_char(char *s1, char charactere)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen_int(s1);
	str = (char *)malloc((size + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = charactere;
	str[i + 1] = '\0';
	if (s1)
		free (s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_read	strct = {.fd = -1};
	char			*str;
	char			charactere;

	str = NULL;
	if (strct.fd != fd)
	{
		if (!init_check(fd, &strct))
			return (NULL);
	}
	charactere = read_check(&strct);
	while (charactere)
	{
		if (charactere == '\n')
			return (str);
		str = ft_strjoin_char(str, charactere);
		charactere = read_check(&strct);
	}
	return (str);
}
