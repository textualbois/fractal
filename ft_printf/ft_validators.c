/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:47:17 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:24:51 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_is_valid(char flag)
{
	if (ft_isdigit(flag))
		return (1);
	if (flag == ' ')
		return (1);
	if (flag == '-')
		return (1);
	if (flag == '+')
		return (1);
	if (flag == '#')
		return (1);
	if (flag == '.')
		return (1);
	else
		return (0);
}

int	flag_group_valid(char *str, size_t i, size_t offset)
{
	size_t	j;

	while (offset < i - 1)
	{
		j = offset;
		if (str[offset] == '.')
		{
			while (++j < i)
			{
				if (!ft_isdigit(str[j]))
					return (0);
			}
		}
		else if (str[offset] != '0' && ft_isdigit(str[offset]))
		{
			while (++j < i)
			{
				if (!ft_isdigit(str[j]) && str[j] != '.')
					return (0);
			}
		}
		offset++;
	}
	return (1);
}
