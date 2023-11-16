/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_excp_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:58:16 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:24:49 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gen_excp(char *fmt, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strchr(fmt, ' ') && (ft_strchr(fmt, 'd') || ft_strchr(fmt, 'i')))
		str = space_header(str);
	if (ft_strchr(fmt, '#') && (ft_strchr(fmt, 'x') || ft_strchr(fmt, 'X')))
		str = hex_header(fmt, str);
	if (ft_strchr(fmt, '+') && (ft_strchr(fmt, 'i') || ft_strchr(fmt, 'd')))
		str = plus_header(str, len);
	len = ft_strlen(str);
	if (ft_strchr(fmt, '.'))
		str = precision(fmt, str);
	if (fmt[1] == '0' && !ft_strchr(fmt, '.') && !ft_strchr(fmt, '-'))
		str = zeroed(fmt, str);
	str = min_width(fmt, str);
	if (ft_strchr(fmt, '-'))
		left_aligned(str, len);
	return (str);
}

char	*gen_excp_str(char *fmt, char *str)
{
	size_t	len;

	if (fmt[1] == '0' && !ft_strchr(fmt, '.') && !ft_strchr(fmt, '-') \
		&& str[0] == '%')
		str = zeroed(fmt, str);
	if (ft_strchr(fmt, '.'))
		str = precision_str(fmt, str);
	len = ft_strlen(str);
	str = min_width(fmt, str);
	if (ft_strchr(fmt, '-'))
		left_aligned(str, len);
	return (str);
}

char	*gen_excp_adr(char *fmt, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	str = min_width(fmt, str);
	if (ft_strchr(fmt, '-'))
		left_aligned(str, len);
	return (str);
}

t_list	*gen_excp_chr(t_list *temp2, t_list **lst, t_list *elem, int arg)
{
	char	*spaces;
	char	*spaces_cut;
	t_list	*temp;
	t_list	*new;

	spaces = min_width(elem->content, ft_strdup(""));
	spaces_cut = ft_substr(spaces, 1, ft_strlen(spaces));
	free(spaces);
	temp = ft_lstnew(spaces_cut);
	if (ft_strchr((char *)elem->content, '-'))
	{
		new = ft_lst_insert(*lst, &elem, temp2);
		new->next = temp;
		temp->next = elem->next;
	}
	else
	{
		new = ft_lst_insert(*lst, &elem, temp);
		new->next = temp2;
		temp2->next = elem->next;
	}
	if (arg == 0)
		temp2->len = 1;
	return (new);
}
