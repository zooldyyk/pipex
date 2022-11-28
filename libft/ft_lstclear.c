/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:54:53 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/29 11:56:56 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*block;

	if (lst)
	{
		while (*lst)
		{
			block = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = block;
		}
	}
}
