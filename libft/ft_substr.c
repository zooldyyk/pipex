/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:10:24 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/22 14:33:12 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (len > size && i >= start)
		{	
			str[size] = s[i];
			size++;
		}
		i++;
	}
	str[size] = '\0';
	return (str);
}
/*
int	main()
{
	printf("%s\n", ft_substr("salut", 2, 3));
}*/
