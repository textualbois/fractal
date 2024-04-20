/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:56:04 by isemin            #+#    #+#             */
/*   Updated: 2023/11/16 12:24:36 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_node(char *flags, int c_count, va_list aptr)
{
	t_res	*output;
	char	type_alias;
	int		temp_count;

	if (ft_strlen(flags) == 1)
		type_alias = ' ';
	else
		type_alias = flags[ft_strlen(flags) - 1];
	output = format_content(flags, type_alias, aptr);
	if (output == NULL)
		c_count = -1;
	else
	{
		temp_count = write(1, output->content, output->len);
		if (temp_count == -1)
			return (-1);
		c_count += temp_count;
	}
	ft_lstdelone((t_list *)output, free);
	return (c_count);
}

static int	print_lst(t_list *head_node, va_list aptr)
{
	t_list	*temp;
	int		c_count;

	c_count = 0;
	temp = head_node;
	while (temp != NULL && c_count != -1)
	{
		c_count = print_node(temp->content, c_count, aptr);
		temp = temp->next;
	}
	return (c_count);
}

int	ft_printf(const char *str, ...)
{
	t_list	*parsed_lst;
	int		res;
	va_list	aptr;
	char	*temp_str;

	if (ft_strlen(str) == 0)
		return (0);
	temp_str = (char *)str;
	va_start(aptr, str);
	parsed_lst = ft_input_parser(temp_str);
	if (parsed_lst != NULL)
	{
		res = print_lst(parsed_lst, aptr);
		ft_lstclear(&parsed_lst, free);
	}
	else
		res = -1;
	va_end(aptr);
	return (res);
}
