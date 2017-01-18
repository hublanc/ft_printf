/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_lower_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:42:05 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 15:39:38 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_lower_hexa(va_list *arg, t_flag *flag)
{
	uintmax_t		hex;
	int				len;

	hex = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag_ui(hex, flag, 16);
	write_padleft_uint(flag, len, hex, 1);
	if (!(flag->prec && flag->precision == 0 && hex == 0))
		get_ui(hex, "0123456789abcdef", 16);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
