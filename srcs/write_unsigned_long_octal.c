/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_long_octal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:39:23 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/19 19:28:22 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_unsigned_long_octal(va_list *arg, t_flag *flag)
{
	unsigned long int	nb;
	int					len;

	nb = va_arg(*arg, unsigned long int);
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
