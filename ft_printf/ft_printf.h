/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:45:00 by isemin            #+#    #+#             */
/*   Updated: 2023/11/15 01:24:00 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_flags
{
	char				type;
	int					upper;
	int					prefix;
	char				prfx_c;
	int					padding;
	size_t				min_width;
	size_t				precision;
}						t_flags;

typedef struct s_res
{
	char				*content;
	size_t				len;
}						t_res;

int		ft_printf(const char *str, ...);
t_res	*format_content(char *content, char type_alias, va_list aptr);
t_res	*format_char(char *content, int c);
t_res	*format_str(char *content, char *str);
t_res	*format_hex(char *content, unsigned long val, int prefix, int upper);
t_res	*format_nums(char *content, int val, char type);
t_res	*format_u_nums(char *content, unsigned int uval, char type);
t_list	*ft_input_parser(char *str);
int		flag_is_valid(char flag);
int		flag_group_valid(char *str, size_t i, size_t offset);
size_t	ft_get_ttl_len_nums(size_t str_len, t_flags *flags, int require_pfx);
size_t	ft_get_ttl_len_hex(size_t str_len, t_flags *flags, int require_pfx);
size_t	ft_get_ttl_len_str(size_t str_len, size_t min_width, size_t prec);
char	*ft_rebase_ulong(unsigned long nbr, char *base);
size_t	hex_len(unsigned long n, size_t base_size);
size_t	int_len(int n);
size_t	u_num_len(unsigned long n);
void	lower_string(char **str);
size_t	precsn_space_n(size_t ttl_l, size_t base_l, t_flags *flags, size_t pos);
size_t	prec_space_h(size_t ttl_l, unsigned long val, t_flags *flags, size_t p);
size_t	put_prfx_prec_h(size_t val, t_flags *flags, char **res, size_t p);
size_t	put_padding4hex(size_t val, t_flags *flags, char **res, size_t pos);
size_t	put_prfx_precision_n(size_t val, t_flags *flags, char **res, size_t p);
size_t	put_padding4nums(size_t val, t_flags *flags, char **res, size_t p);

#endif
