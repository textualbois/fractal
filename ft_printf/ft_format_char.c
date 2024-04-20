/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:55:04 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 00:05:58 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pull_args(char	*content, size_t p, int *padding, size_t *min_width)
{
	if (content[p] == '0' && *padding > 0 && *min_width == 0)
		*padding = 0;
	else if (content[p] == '-')
		*padding = -1;
	else if (ft_isdigit(content[p]))
		*min_width = *min_width * 10 + (content[p] - 48);
}

static t_res	*form_string_c(int padding, size_t min_width, int c)
{
	t_res	*res;
	size_t	pos;

	res = (t_res *)malloc(sizeof(t_res));
	res->len = min_width + (min_width == 0);
	res->content = calloc(res->len + 1, 1);
	if (res == NULL || res->content == NULL)
	{
		ft_lstdelone((t_list *)res, free);
		return (NULL);
	}
	pos = 0;
	if (padding == -1)
		(res->content)[pos++] = c;
	while (pos + (padding > -1) < min_width)
	{
		if (padding == 0)
			(res->content)[pos++] = '0';
		else
			(res->content)[pos++] = ' ';
	}
	if (padding != -1)
		(res->content)[pos++] = c;
	(res->content)[pos] = '\0';
	return (res);
}

t_res	*format_char(char *content, int c)
{
	size_t	pos;
	int		padding;
	size_t	min_width;

	min_width = 0;
	padding = 1;
	pos = 1;
	while (content[pos] != 'c' && content[pos] != '%' && content[pos] != '.')
	{
		pull_args(content, pos, &padding, &min_width);
		pos++;
	}
	return (form_string_c(padding, min_width, c));
}
