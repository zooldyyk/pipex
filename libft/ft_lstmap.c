/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:55:53 by eschmid           #+#    #+#             */
/*   Updated: 2021/10/29 11:55:55 by eschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*block_f;

	if (!lst)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		block_f = ft_lstnew(f(lst->content));
		if (!block_f)
			ft_lstclear(&block_f, (*del));
		else
			ft_lstadd_back(&lst2, block_f);
		lst = lst->next;
	}
	return (lst2);
}
