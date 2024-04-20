/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:30:48 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:25:57 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pull_args(char *content, t_flags *flags, size_t *pos)
{
	if (content[*pos] == '0' && flags->padding > 0 && flags->min_width == 0)
		flags->padding = 0;
	else if (content[*pos] == '-')
		flags->padding = -1;
	else if (content[*pos] == '#')
		flags->prefix = 2;
	else if (ft_isdigit(content[*pos]))
		flags->min_width = flags->min_width * 10 + (content[*pos] - 48);
}

static void	set_precision(char	*cntnt, size_t *p, t_flags *flags, int put_prfx)
{
	if (cntnt[*p] == '.')
	{
		if (flags->padding == 0)
			flags->padding = 1;
		*p += 1;
		flags->precision = 0;
		while (ft_isdigit(cntnt[*p]))
		{
			flags->precision = flags->precision * 10 + cntnt[*p] - 48;
			*p += 1;
		}
		*p -= 1;
	}
	if (flags->padding == 0)
	{
		if (flags->min_width > flags->precision + flags->prefix * put_prfx)
			flags->precision = flags->min_width - flags->prefix * put_prfx;
	}
}

static t_res	*form_string_hex(unsigned long val, t_flags *flags)
{
	t_res	*res;
	size_t	pos;
	size_t	base_len;
	int		put_val;

	put_val = (val != 0 || flags->precision != 0 || flags->type == 'p');
	base_len = hex_len(val, 16);
	res = (t_res *)malloc(sizeof(t_res));
	res->len = ft_get_ttl_len_hex(base_len, flags, put_val);
	res->content = (char *)calloc(res->len + 1, 1);
	if (res == NULL)
		return (NULL);
	pos = 0;
	if (flags->padding == -1)
		pos = put_prfx_prec_h(val, flags, &(res->content), pos);
	pos = put_padding4hex(val, flags, &(res->content), pos);
	if (flags->padding != -1)
		pos = put_prfx_prec_h(val, flags, &(res->content), pos);
	if (flags->upper != 1)
		lower_string(&(res->content));
	res->len = pos;
	return (res);
}

t_res	*format_hex(char *content, unsigned long val, int prefix, int upper)
{
	size_t	pos;
	t_flags	*flags;
	t_res	*res;

	flags = malloc(sizeof(t_flags));
	flags->type = content[ft_strlen(content) - 1];
	flags->precision = hex_len(val, 16);
	flags->min_width = 0;
	flags->padding = 1;
	flags->upper = upper;
	flags->prefix = prefix;
	pos = 1;
	while (content[pos] != flags->type && \
		content[pos] != '%' && \
		content[pos] != '.')
	{
		pull_args(content, flags, &pos);
		pos++;
	}
	set_precision(content, &pos, flags, (val != 0 || flags->type == 'p'));
	res = form_string_hex(val, flags);
	free(flags);
	return (res);
}
