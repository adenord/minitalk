/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:30:42 by adenord           #+#    #+#             */
/*   Updated: 2023/10/24 16:24:23 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*formater(int len, int zeros, char *minus, char *str)
{
	char	*cut;
	int		i;

	i = -1;
	if (str[0] == '-')
		i++;
	if (zeros > len)
		cut = ft_calloc((zeros + 1), sizeof(char));
	else
		return (str);
	if (minus)
		cut[0] = '-';
	while (++i < (zeros - len))
		cut[i] = '0';
	if (!minus)
		ft_strcat(cut, str);
	else
		ft_strcat(cut, minus);
	free(str);
	return (cut);
}

char	*zeroed(char *fmt, char *str)
{
	int		len;
	int		zeros;
	char	*cut;
	char	*minus;

	minus = NULL;
	len = ft_strlen(str);
	zeros = ft_atoi(&fmt[1]);
	if (str[0] == '-')
	{
		minus = &str[1];
		zeros++;
	}
	cut = formater(len, zeros, minus, str);
	return (cut);
}

char	*precision(char *fmt, char *str)
{
	int		len;
	int		zeros;
	char	*cut;
	char	*minus;

	minus = NULL;
	len = ft_strlen(str);
	cut = ft_strchr(fmt, '.');
	zeros = ft_atoi(&cut[1]);
	if (zeros == 0 && ft_atoi(str) == 0 && \
		ft_strlen(str) == 1 && !ft_isalpha(str[0]))
	{
		free(str);
		return (ft_strdup(""));
	}
	if (str[0] == '-')
	{
		len--;
		minus = &str[1];
		zeros++;
	}
	cut = formater(len, zeros, minus, str);
	return (cut);
}

char	*min_width(char *fmt, char *str)
{
	int		min_width;
	int		len;
	char	*ret;
	int		i;

	i = 0;
	len = ft_strlen(str);
	min_width = 0;
	while ((!ft_isdigit(fmt[i]) || fmt[i] == '0') && fmt[i] && fmt[i] != '.')
		i++;
	if (fmt[i - 1] == '0' || fmt[i - 1] == '-' || fmt[i - 1] == '%' \
		|| fmt[i - 1] == '+' || fmt[i - 1] == ' ')
		min_width = ft_atoi(&fmt[i]);
	i = -1;
	if (min_width > len)
	{
		ret = ft_calloc(min_width + 1, sizeof(char));
		while (++i < (min_width - len))
			ret[i] = ' ';
		ft_strcat(ret, str);
		free(str);
		return (ret);
	}
	return (str);
}

void	left_aligned(char *str, size_t len)
{
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (str[i] == ' ' && i < (ft_strlen(str) - len) && str[i])
		i++;
	while (str[i])
	{
		str[y] = str[i];
		i++;
		y++;
	}
	while (str[y])
	{
		str[y] = ' ';
		y++;
	}
}
