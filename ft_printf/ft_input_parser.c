/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:37:24 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:24:58 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*flag_lookahead(char *str)
{
	size_t	i;
	char	*content;
	char	needle[2];

	i = 1;
	content = malloc(2);
	if (content == NULL)
		return (NULL);
	ft_strlcpy(content, &(str[0]), 2);
	needle[1] = '\0';
	needle[0] = str[i];
	while (ft_strnstr("cspdiuxX", needle, 8) == NULL && str[i] != '%')
	{
		if (flag_is_valid(str[i++]) == 0)
			return (content);
		needle[0] = str[i];
	}
	if (flag_group_valid(str, i, 1))
	{
		free(content);
		content = malloc(i + 2);
		if (content != NULL)
			ft_strlcpy(content, str, i + 2);
	}
	return (content);
}

static char	*get_section(char **str, char *limit)
{
	char	*flags;

	if (limit == NULL)
		limit = *str + ft_strlen(*str);
	if (*str == limit)
	{
		flags = flag_lookahead(*str);
		if (flags == NULL)
			return (NULL);
	}
	else
	{
		flags = (char *)malloc((size_t)(limit - *str) + 1);
		if (flags == NULL)
			return (NULL);
		ft_strlcpy(flags, *str, (size_t)(limit - *str) + 1);
	}
	*str = *str + ft_strlen(flags);
	return (flags);
}

t_list	*ft_input_parser(char *str)
{
	char	*format_spec;
	char	*limit;
	t_list	*head_node;
	t_list	*current_node;

	limit = ft_strchr(str, '%');
	format_spec = get_section(&str, (char *)limit);
	head_node = ft_lstnew(format_spec);
	current_node = head_node;
	while (*str != '\0')
	{
		if (current_node == NULL || current_node->content == NULL)
		{
			if (format_spec != NULL)
				free(format_spec);
			ft_lstclear(&head_node, free);
			return (NULL);
		}
		limit = ft_strchr(str, '%');
		format_spec = get_section(&str, (char *)limit);
		current_node->next = ft_lstnew(format_spec);
		current_node = current_node->next;
	}
	return (head_node);
}
