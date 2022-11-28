/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:25:08 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/20 13:33:12 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((unsigned char)s1[c] == (unsigned char)s2[c]
		&& s1[c] != '\0' && c < n)
		c++;
	if (c == n)
		return (0);
	else
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
/*
int main ()
{
	const char *s1 = "loh";
	const char *s2 = "lloho";
	size_t n = 1;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}*/
