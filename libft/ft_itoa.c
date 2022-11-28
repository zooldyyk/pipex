/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:34:02 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/29 13:43:16 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include "libft.h"

void	*ft_strcpy2(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i++])
		dest[i] = src[i];
	return (dest);
}

size_t	ft_nb_len(int n)
{
	size_t	count;

	count = 0;
	if (n == -2147483648)
		return (count = 11);
	while (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_glitchnorminette(int nb, char *str, size_t size)
{
	int	i;

	i = size;
	if (nb == -2147483648)
		ft_strcpy2(str, "-2147483648");
	if (!nb)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	str[size + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		nb;

	if (n > 2147483647 || n < -2147483648)
		return (NULL);
	size = ft_nb_len(n);
	nb = n;
	str = malloc((sizeof(char) * size) + 1);
	if (!str)
		return (NULL);
	return (ft_glitchnorminette(nb, str, size));
}
/*
int main()
{
	printf("%s\n", ft_itoa(1008756521));	
	printf("%s\n", itoa(1008756521));
}*/
