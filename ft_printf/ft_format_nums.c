/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:30:18 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:27:09 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pull_args(char	*content, t_flags *flags, size_t *pos, int sign)
{
	if (content[*pos] == '0' && flags->padding > 0 && flags->min_width == 0)
		flags->padding = 0;
	else if (content[*pos] == '-')
		flags->padding = -1;
	else if (sign != 0 && content[*pos] == ' ' && flags->prefix != 1)
	{
		flags->prefix = 1;
		flags->prfx_c = ' ';
	}
	else if (sign != 0 && content[*pos] == '+' && flags->prefix != 1)
	{
		flags->prefix = 1;
		flags->prfx_c = '+';
	}
	else if (ft_isdigit(content[*pos]))
		flags->min_width = flags->min_width * 10 + (content[*pos] - 48);
}

static void	set_precision(char	*content, size_t *pos, t_flags *flags)
{
	if (content[*pos] == '.')
	{
		if (flags->padding == 0)
			flags->padding = 1;
		*pos += 1;
		flags->precision = 0;
		while (ft_isdigit(content[*pos]))
		{
			flags->precision = flags->precision * 10 + content[*pos] - 48;
			*pos += 1;
		}
		*pos -= 1;
	}
	if (flags->padding == 0)
	{
		if (flags->min_width > flags->precision + flags->prefix)
			flags->precision = flags->min_width - flags->prefix;
	}
}

static t_res	*form_string_nums(unsigned int val, t_flags *flags)
{
	t_res	*res;
	size_t	pos;
	size_t	base_len;
	int		put_num;

	put_num = (val != 0 || flags->precision != 0);
	res = (t_res *)malloc(sizeof(t_res));
	base_len = u_num_len(val);
	res->len = ft_get_ttl_len_nums(base_len, flags, put_num);
	res->content = (char *)calloc(res->len + 1, 1);
	if (res == NULL)
		return (NULL);
	pos = 0;
	if (flags->padding == -1)
		pos = put_prfx_precision_n(val, flags, &(res->content), pos);
	pos = put_padding4nums(val, flags, &(res->content), pos);
	if (flags->padding != -1)
		pos = put_prfx_precision_n(val, flags, &(res->content), pos);
	return (res);
}

t_res	*format_nums(char *content, int val, char type)
{
	size_t			pos;
	t_flags			*flags;
	t_res			*res;
	unsigned int	uval;

	flags = malloc(sizeof(t_flags));
	flags->precision = int_len(val) - (val < 0);
	flags->min_width = 0;
	flags->padding = 1;
	flags->upper = 0;
	flags->prefix = (val < 0);
	flags->prfx_c = '\0';
	if (flags->prefix == 1)
		flags->prfx_c = '-';
	uval = (unsigned int)(val * (val >= 0) - val * (val < 0));
	pos = 1;
	while (content[pos] != type && content[pos] != '%' && content[pos] != '.')
	{
		pull_args(content, flags, &pos, val >= 0);
		pos++;
	}
	set_precision(content, &pos, flags);
	res = form_string_nums(uval, flags);
	free(flags);
	return (res);
}

t_res	*format_u_nums(char *content, unsigned int uval, char type)
{
	size_t	pos;
	t_flags	*flags;
	t_res	*res;

	flags = malloc(sizeof(t_flags));
	flags->precision = u_num_len(uval);
	flags->min_width = 0;
	flags->padding = 1;
	flags->upper = 0;
	flags->prefix = 0;
	flags->prfx_c = '\0';
	pos = 1;
	while (content[pos] != type && content[pos] != '%' && content[pos] != '.')
	{
		pull_args(content, flags, &pos, 0);
		pos++;
	}
	set_precision(content, &pos, flags);
	res = form_string_nums(uval, flags);
	free(flags);
	return (res);
}
