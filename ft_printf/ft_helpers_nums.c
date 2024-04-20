/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:25:09 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:27:44 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_ttl_len_nums(size_t str_len, t_flags *flags, int put_num)
{
	size_t	res;

	res = str_len;
	if (res < flags->precision)
		res = flags->precision;
	res = res * put_num + flags->prefix * (put_num || flags->prfx_c != '-');
	if (res < flags->min_width)
		res = flags->min_width;
	return (res);
}

size_t	precsn_space_n(size_t ttl_l, size_t base_l, t_flags *flags, size_t p)
{
	if (flags->padding == -1)
	{
		if (flags->precision > base_l)
		{
			if (p + base_l < flags->precision + flags->prefix)
				return (1);
		}
	}
	else
	{
		if (p + base_l < ttl_l)
			return (1);
	}
	return (0);
}

size_t	put_prfx_precision_n(size_t val, t_flags *flags, char **res, size_t p)
{
	size_t	base_len;
	size_t	ttl_len;
	char	*res_str;
	int		put_num_b;

	put_num_b = (val != 0 || flags->precision != 0);
	base_len = u_num_len(val);
	ttl_len = ft_get_ttl_len_nums(base_len, flags, put_num_b);
	if (flags->prefix == 1)
		(*res)[p++] = flags->prfx_c;
	while (precsn_space_n(ttl_len, base_len, flags, p) == 1)
	{
		(*res)[p] = '0';
		p++;
	}
	res_str = ft_rebase_ulong(val, "0123456789");
	if (val != 0 || flags->precision != 0)
		p = ft_strlcat(*res, res_str, p + base_len + 1);
	else if (flags->min_width != 0)
		p = ft_strlcat(*res, " \0", p + 1 + 1);
	free(res_str);
	return (p);
}

size_t	put_padding4nums(size_t val, t_flags *flags, char **res, size_t p)
{
	size_t	limit;
	size_t	ttl_len;
	size_t	base_len;

	base_len = u_num_len(val);
	ttl_len = ft_get_ttl_len_nums(base_len, flags, \
		(val != 0 || flags->precision != 0));
	while (flags->padding == -1 && p < ttl_len)
		(*res)[p++] = ' ';
	if (flags->padding != -1)
	{
		limit = base_len * (val != 0 || flags->precision != 0);
		if (limit < flags->precision)
			limit = flags->precision;
		while (p + flags->prefix + limit < ttl_len)
		{
			if (flags->padding == 0)
				(*res)[p++] = '0';
			else
				(*res)[p++] = ' ';
		}
	}
	return (p);
}
