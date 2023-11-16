/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:16:02 by adenord           #+#    #+#             */
/*   Updated: 2023/10/25 15:42:04 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ********************************************************************* */
/*                                                                       */
/*  applies a function to each element of a list by creating a new list  */
/*                                                                       */
/* ********************************************************************* */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*belly;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	first = NULL;
	while (lst)
	{
		belly = (*f)(lst->content);
		new = ft_lstnew(belly);
		if (!new)
		{
			free(belly);
			ft_lstclear(&first, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
