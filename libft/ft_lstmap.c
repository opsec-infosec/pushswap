/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:06:57 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:09:27 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Creates a list of elements and applies the function to the element
 **/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cur;

	if (!f || !lst)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (!newlst)
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	cur = newlst;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = ft_lstnew((*f)(lst->content));
		if (!cur->next)
		{
			ft_lstclear(&newlst, del);
			break ;
		}
		cur = cur->next;
	}
	return (newlst);
}
