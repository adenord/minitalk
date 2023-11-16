/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:50:01 by adenord           #+#    #+#             */
/*   Updated: 2023/08/05 10:12:44 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_insert(t_list *lst, t_list **elem, t_list *new)
{
	while (lst->next != *elem)
		lst = lst->next;
	new->next = *elem;
	lst->next = new;
	return (new);
}
