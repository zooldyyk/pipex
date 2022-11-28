/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:43:42 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/29 11:48:23 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_counter(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		count++;
		while (*str && *str != c)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (count);
}

static int	ft_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **result, int i)
{
	while (i--)
		free(result[i]);
	free(result);
	return ;
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		i;
	int		count;

	i = 0;
	if (!str)
		return (NULL);
	count = ft_words_counter((char *)str, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*str == c && *str)
			str++;
		result[i] = ft_substr((char *)str, 0, ft_len((char *)str, c));
		if (result[i] == NULL)
			ft_free(result, i);
		str = str + ft_len((char *)str, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
