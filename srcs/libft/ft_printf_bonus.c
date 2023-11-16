/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:17:26 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:21:41 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_lst(void *content)
{
	free(content);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*lst;
	size_t		len;

	va_start(args, format);
	lst = cutting(format);
	replace_and_add(&lst, args);
	display_list(lst);
	len = ft_lst_strlen(lst);
	ft_lstclear(&lst, &del_lst);
	va_end(args);
	return (len);
}
