/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_integer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:05:38 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:55:39 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*fct_integer(t_list **lst, t_list *elem, int arg)
{
	t_list	*new;
	char	*content;

	content = elem->content;
	if (ft_strlen(content) == 2)
		new = ft_lst_insert(*lst, &elem, ft_lstnew(ft_itoa(arg)));
	else
		new = ft_lst_insert(*lst, &elem, \
		ft_lstnew(gen_excp(content, ft_itoa(arg))));
	new->next = elem->next;
	free(elem->content);
	free(elem);
	return (new);
}
