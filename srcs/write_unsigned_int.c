/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:54:16 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 15:46:52 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_unsigned_int(va_list *arg, t_flag *flag)
{
	uintmax_t		nb;
	int				len;

	nb = get_utype(arg, flag);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag_ui(nb, flag, 10);
	write_padleft_uint(flag, len, nb, 0);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_ui(nb, "0123456789", 10);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
