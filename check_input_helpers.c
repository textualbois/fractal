/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:23:20 by isemin            #+#    #+#             */
/*   Updated: 2024/04/24 18:23:41 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	ft_isdouble(char *str)
{
	int	i;
	int	dot_count;
	int	sign_count;

	i = 0;
	dot_count = 0;
	sign_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			sign_count++;
		else if (str[i] == '.')
			dot_count++;
		else if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (dot_count < 2 && sign_count < 2 && i > 0)
		return (1);
	return (0);
}

int	ft_isint(char *str)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			sign_count++;
		else if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (sign_count < 2 && i > 0)
		return (1);
	return (0);
}
