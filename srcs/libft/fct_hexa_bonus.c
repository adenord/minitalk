/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_hexa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:13:11 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:22:16 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_hexa(int nbr, char *base)
{
	long	ov;
	char	ret[9];
	int		i;

	i = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr > 2147483647 || nbr == -2147483648)
		return (ft_strdup("80000000"));
	if (nbr < 0)
	{
		nbr = -nbr;
		ov = (4294967295 - nbr) + 1;
	}
	else
		ov = nbr;
	while (ov > 0)
	{
		ret[i] = base[ov % 16];
		ov /= 16;
		i++;
	}
	ret[i] = '\0';
	ft_strrev(ret);
	return (ft_strdup(ret));
}

static void	x_or_x(char *base, char op)
{
	if (op == 'x')
		ft_strcpy(base, "0123456789abcdef");
	else if (op == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
}

t_list	*fct_hexa(t_list **lst, t_list *elem, int arg, char op)
{
	t_list	*new;
	t_list	*temp;
	char	*content;
	char	base[17];

	x_or_x(base, op);
	content = elem->content;
	if (ft_strlen(content) != 2)
		temp = ft_lstnew(gen_excp(content, convert_hexa(arg, base)));
	else
		temp = ft_lstnew(convert_hexa(arg, base));
	new = ft_lst_insert(*lst, &elem, temp);
	new->next = elem->next;
	free(elem->content);
	free(elem);
	return (new);
}
