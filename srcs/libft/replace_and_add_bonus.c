/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_and_add_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:34:18 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:23:09 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	replace_and_add(t_list **lst, va_list args)
{
	char	*temp;
	t_list	*t_temp;
	size_t	kp;

	t_temp = *lst;
	while (t_temp)
	{
		temp = t_temp->content;
		kp = ft_strlen(temp) - 1;
		if (temp[0] == '%' && (temp[kp] == 'd' || temp[kp] == 'i'))
			t_temp = fct_integer(lst, t_temp, va_arg(args, int));
		if (temp[0] == '%' && temp[kp] == 's')
			t_temp = fct_string(lst, t_temp, va_arg(args, char *));
		if (temp[0] == '%' && temp[kp] == '%')
			t_temp = fct_string(lst, t_temp, "%");
		if (temp[0] == '%' && temp[kp] == 'c')
			t_temp = fct_character(lst, t_temp, va_arg(args, int));
		if (temp[0] == '%' && temp[kp] == 'u')
			t_temp = fct_unsigned(lst, t_temp, va_arg(args, int));
		if (temp[0] == '%' && (temp[kp] == 'X' || temp[kp] == 'x'))
			t_temp = fct_hexa(lst, t_temp, va_arg(args, int), temp[kp]);
		if (temp[0] == '%' && temp[kp] == 'p')
			t_temp = fct_address(lst, t_temp, va_arg(args, long));
		t_temp = t_temp->next;
	}
}
