/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:15:05 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/19 19:25:44 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_octal(va_list *arg, t_flag *flag)
{
	uintmax_t		nb;
	int				len;

	nb = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag_ui(nb, flag, 8);
	if (flag->ht && flag->precision > 0)
	{
		flag->precision--;
		len--;
	}
	write_padleft_uint(flag, len, nb, 3);
	if (!(flag->prec && flag->precision == 0 && nb == 0)
		&& !(flag->ht && nb == 0))
		get_ui(nb, "012345678", 8);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
