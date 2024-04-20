/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:23:31 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:21:50 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_res	*format_content(char *content, char type_alias, va_list aptr)
{
	if (content[0] != '%')
		return (format_str("%s", content));
	else if (type_alias == '%')
		return (format_char(content, '%'));
	else if (type_alias == 'c')
		return (format_char(content, va_arg(aptr, int)));
	else if (type_alias == 's')
		return (format_str(content, va_arg(aptr, char *)));
	else if (type_alias == 'p')
		return (format_hex(content, va_arg(aptr, unsigned long), 2, 0));
	else if (type_alias == 'd' || type_alias == 'i')
		return (format_nums(content, va_arg(aptr, int), type_alias));
	else if (type_alias == 'u')
		return (format_u_nums(content, va_arg(aptr, unsigned int), type_alias));
	else
		return (format_hex(content, \
			(unsigned int)va_arg(aptr, int), 0, (type_alias == 'X')));
}
