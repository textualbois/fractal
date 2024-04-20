/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:12:52 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:12:54 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_ttl_len_str(size_t str_len, size_t min_width, size_t prec)
{
	size_t	res;

	res = str_len;
	if (res > prec)
		res = prec;
	if (res < min_width)
		res = min_width;
	return (res);
}
