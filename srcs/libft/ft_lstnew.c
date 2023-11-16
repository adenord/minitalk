/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:19:42 by adenord           #+#    #+#             */
/*   Updated: 2023/08/06 16:35:12 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* **************************** */
/*                              */
/*  creates a new list element  */
/*                              */
/* **************************** */

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->content = content;
	lst->len = ft_strlen((char *)content);
	return (lst);
}
