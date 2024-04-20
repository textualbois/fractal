/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:00:39 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:26:14 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lower_string(char **str)
{
	size_t	pos;
	char	temp;

	pos = 0;
	while ((*str)[pos] != '\0')
	{
		temp = (*str)[pos];
		temp = ft_tolower(temp);
		(*str)[pos] = temp;
		pos++;
	}
}

size_t	ft_get_ttl_len_hex(size_t str_len, t_flags *flags, int put_val)
{
	size_t	res;

	res = str_len;
	if (res < flags->precision)
		res = flags->precision;
	res = res * (put_val || flags->precision != 0) + flags->prefix * put_val;
	if (res < flags->min_width)
		res = flags->min_width;
	return (res);
}

size_t	prec_space_h(size_t ttl_l, unsigned long val, t_flags *flags, size_t p)
{
	size_t	base_len;

	base_len = hex_len(val, 16);
	if (flags->padding == -1)
	{
		if (flags->precision > base_len)
		{
			if (p + base_len < flags->precision + \
				flags->prefix * (val != 0 || flags->type == 'p'))
				return (1);
		}
	}
	else
	{
		if (p + base_len < ttl_l)
			return (1);
	}
	return (0);
}

size_t	put_prfx_prec_h(size_t val, t_flags *flags, char **res, size_t p)
{
	size_t	base_len;
	size_t	ttl_len;
	char	*res_str;
	int		put_val;

	put_val = (val != 0 || flags->type == 'p');
	base_len = hex_len(val, 16);
	ttl_len = ft_get_ttl_len_hex(base_len, flags, put_val);
	if (flags->prefix == 2 && (val != 0 || flags->type == 'p'))
		p = ft_strlcat(*res, "0X\0", ttl_len);
	while (prec_space_h(ttl_len, val, flags, p) == 1)
	{
		(*res)[p] = '0';
		p++;
	}
	res_str = ft_rebase_ulong(val, "0123456789ABCDEF");
	if (val != 0 || flags->precision != 0)
		p = ft_strlcat(*res, res_str, p + base_len + 1);
	else if (flags->min_width != 0)
		p = ft_strlcat(*res, " ", p + 1 + 1);
	free(res_str);
	return (p);
}

size_t	put_padding4hex(size_t val, t_flags *flags, char **res, size_t p)
{
	size_t	limit;
	size_t	ttl_len;
	size_t	base_len;

	base_len = hex_len(val, 16);
	ttl_len = ft_get_ttl_len_hex(base_len, flags, \
		(val != 0 || flags->type == 'p'));
	if (flags->padding == -1)
	{
		while (p < ttl_len)
			(*res)[p++] = ' ';
	}
	else
	{
		limit = base_len;
		if (limit < flags->precision)
			limit = flags->precision;
		while (p + flags->prefix * (val != 0 || flags->type == 'p') + \
			limit < ttl_len)
			(*res)[p++] = ' ';
	}
	return (p);
}
