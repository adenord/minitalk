/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_string_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:15:40 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:23:32 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*fct_string(t_list **lst, t_list *elem, char *arg)
{
	t_list	*new;
	t_list	*temp;
	char	*content;
	char	null[7];

	content = elem->content;
	if (!arg)
	{
		ft_strcpy(null, "(null)");
		arg = null;
	}
	if (ft_strlen(content) == 2)
		temp = ft_lstnew(ft_strdup(arg));
	else
		temp = ft_lstnew(gen_excp_str(content, ft_strdup(arg)));
	new = ft_lst_insert(*lst, &elem, temp);
	new->next = elem->next;
	free(elem->content);
	free(elem);
	return (new);
}
