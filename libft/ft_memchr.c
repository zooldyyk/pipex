/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:53:09 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/20 11:58:06 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*yazebi;
	unsigned char	zebi;
	size_t			i;

	i = 0;
	yazebi = (unsigned char *)s;
	zebi = (unsigned char)c;
	while (i < n)
	{
		if (*yazebi == zebi)
			return (yazebi);
		i++;
		yazebi++;
	}
	return (NULL);
}
/*
int	main()
{
	char	*s = "salut";
	printf("%s\n", s);
	printf("%s\n", ft_memchr(s, 'l', 3));
}*/
