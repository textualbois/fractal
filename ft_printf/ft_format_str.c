/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:05:40 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 00:44:00 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_res	*allocate_res(size_t str_len, size_t min_width, size_t prec)
{
	t_res	*res;

	res = (t_res *)malloc(sizeof(t_res));
	if (res == NULL)
		return (NULL);
	res->len = ft_get_ttl_len_str(str_len, min_width, prec);
	res->content = calloc(res->len + 1, 1);
	if (res->content == NULL)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

static void	pull_args(char	*content, size_t *p, int *padding, size_t *m_width)
{
	if (content[*p] == '0' && *padding > 0 && *m_width == 0)
		*padding = 0;
	else if (content[*p] == '-')
		*padding = -1;
	else if (ft_isdigit(content[*p]))
		*m_width = *m_width * 10 + (content[*p] - 48);
}

static void	set_precision(char	*content, size_t *pos, size_t *prec)
{
	if (content[*pos] == '.')
	{
		*pos += 1;
		*prec = 0;
		while (ft_isdigit(content[*pos]))
		{
			*prec = *prec * 10 + content[*pos] - 48;
			*pos += 1;
		}
		*pos -= 1;
	}
}

static t_res	*form_string_s(int padding, size_t m_width, char *s, size_t prc)
{
	t_res	*res;
	size_t	pos;
	size_t	str_len;

	str_len = ft_strlen(s);
	res = allocate_res(str_len, m_width, prc);
	if (res == NULL)
		return (NULL);
	if (padding == -1)
		ft_strlcat(res->content, s, prc + 1);
	pos = ft_strlen(res->content);
	while (pos + (((str_len * (str_len <= prc)) + (prc * (str_len > prc))) * \
		(padding != -1)) < m_width)
	{
		if (padding == 0)
			(res->content)[pos++] = '0';
		else
			(res->content)[pos++] = ' ';
	}
	if (padding != -1)
		pos += ft_strlcat(res->content, s, prc + pos + 1);
	res->len = ft_strlen(res->content);
	return (res);
}

t_res	*format_str(char *content, char *str)
{
	size_t	pos;
	int		padding;
	size_t	min_width;
	size_t	prec;

	prec = 6;
	if (str != NULL)
		prec = ft_strlen(str);
	min_width = 0;
	padding = 1;
	pos = 1;
	while (content[pos] != 's' && content[pos] != '%' && content[pos] != '.')
	{
		pull_args(content, &pos, &padding, &min_width);
		pos++;
	}
	set_precision(content, &pos, &prec);
	if (str != NULL)
		return (form_string_s(padding, min_width, str, prec));
	else
		return (form_string_s(padding, min_width, "(null)", prec));
}
