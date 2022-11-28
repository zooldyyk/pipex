/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:57:15 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/20 13:29:36 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	cc;
	char			*pb;

	pb = b;
	cc = (unsigned char) c;
	while (len--)
	{
		*pb = cc;
		pb++;
	}
	return (b);
}
/*
int	main()
{
	char *str;
	int	c = 'o';
	size_t	len = 2;
	str = ft_strdup("salut");
	

	printf("%s\n", str);
	ft_memset(str, c, len);
	printf("%s\n", str);
}*/
