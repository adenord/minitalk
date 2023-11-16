/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_unsigned_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:31:17 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:22:39 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoun(unsigned int nbr)
{
	char	temp[11];
	int		i;

	i = 0;
	if (nbr == 0)
		return (ft_itoa(nbr));
	while (nbr > 0)
	{
		temp[i] = (nbr % 10) + 48;
		nbr /= 10;
		i++;
	}
	temp[i] = '\0';
	ft_strrev(temp);
	return (ft_strdup(temp));
}

t_list	*fct_unsigned(t_list **lst, t_list *elem, int arg)
{
	unsigned int	ov;
	t_list			*new;
	char			*content;

	ov = (unsigned int)arg;
	content = elem->content;
	if (ft_strlen(content) == 2)
		new = ft_lst_insert(*lst, &elem, ft_lstnew(ft_itoun(ov)));
	else
		new = ft_lst_insert(*lst, &elem, \
		ft_lstnew(gen_excp(content, ft_itoun(ov))));
	new->next = elem->next;
	free(elem->content);
	free(elem);
	return (new);
}
