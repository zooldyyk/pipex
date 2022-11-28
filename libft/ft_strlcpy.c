/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:12:10 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/25 11:31:39 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (0 < dstsize)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*int main ()
{
	const char *src = "helle";
	char *dest = "hello";
	size_t dstsize = 4;
	
		printf("%zu\n", ft_strlcpy(dest, src, dstsize));
        printf("%zu\n", strlcpy(dest, src, dstsize));
		
	
}*/
