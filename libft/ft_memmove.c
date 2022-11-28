/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:23:41 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/20 11:29:56 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
/*int main ()
{
	char src[50] = "sddfsd";
	char dst[50] = "aah";
	ft_memmove(dst,src, 20);
	printf("%s\n", dst);
	printf("%s\n",  memmove(dst, src, 20));
}*/
