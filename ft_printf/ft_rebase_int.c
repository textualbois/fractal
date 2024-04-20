/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rebase_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:43:07 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:20:41 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	hex_len(unsigned long n, size_t base_size)
{
	size_t	size;

	size = (n == 0);
	while (n != 0)
	{
		n /= base_size;
		size++;
	}
	return (size);
}

size_t	u_num_len(unsigned long n)
{
	size_t	size;

	size = (n == 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

size_t	int_len(int n)
{
	size_t	size;

	size = (n <= 0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_rebase_ulong(unsigned long u_nbr, char *base)
{
	char			*rebase_int;
	int				rebased_size;
	size_t			b_size;

	b_size = ft_strlen(base);
	rebased_size = hex_len(u_nbr, b_size);
	rebase_int = calloc(rebased_size + 1, 1);
	if (rebase_int == NULL)
		return (NULL);
	rebase_int[rebased_size] = '\0';
	if (u_nbr != 0)
	{
		while (u_nbr != 0)
		{
			rebase_int[--rebased_size] = base[u_nbr % b_size];
			u_nbr = u_nbr / b_size;
		}
	}
	else
		rebase_int[0] = '0';
	return (rebase_int);
}
