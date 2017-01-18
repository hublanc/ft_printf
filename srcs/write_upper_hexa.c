/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_upper_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:28:31 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 15:46:17 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_upper_hexa(va_list *arg, t_flag *flag)
{
	uintmax_t		hex;
	int				len;

	hex = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag_ui(hex, flag, 16);
	write_padleft_uint(flag, len, hex, 2);
	if (!(flag->prec && flag->precision == 0 && hex == 0))
		get_ui(hex, "0123456789ABCDEF", 16);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
