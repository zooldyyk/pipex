/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:07:03 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/29 14:54:07 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (haystack[0] == '\0')
		return (NULL);
	if (needle[i] == '\0' || needle == NULL)
		return ((char *)haystack);
	while (needle[i] != '\0' && len > j && ft_strlen(haystack))
	{
		while (needle[i] == haystack[j + i] && len > (i + j))
		{
			if (needle[i + 1] == '\0')
				return (&((char *)haystack)[j]);
			i++;
		}
		i = 0;
		j++;
	}
	return (NULL);
}
/*int main(void)
{
    const char haystack[50] = "sa";
    const char	needle[50] = "sal";
    //size_t len = 4;


    printf("%s\n", strnstr(haystack, needle, 6));
	printf("%s\n", ft_strnstr(haystack, needle, 6));		
}*/
