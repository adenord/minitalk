/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strlen_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:15:03 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:24:03 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_strlen(t_list *lst)
{
	int	total_len;

	total_len = 0;
	while (lst)
	{
		total_len += (int)lst->len;
		lst = lst->next;
	}
	return (total_len);
}
