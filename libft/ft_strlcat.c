/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:52:39 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/20 13:29:59 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t i)
{
	size_t	ssize;
	size_t	dsize;

	ssize = ft_strlen(src);
	dsize = ft_strlen(dst);
	if (i < dsize)
		return (ssize + i);
	else
	{
		dst += dsize;
		ft_strlcpy(dst, src, i - dsize);
		return (ssize + dsize);
	}
}
/*
int main ()
{
	char * restrict dst = "WORLD";
   	const char * restrict src = "HELLO";
   	size_t dstsize = 0;

	printf("%zu\n", ft_strlcat(dst, src, dstsize));
}*/
