/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_long_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:36:38 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 15:54:23 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_long_int(va_list *arg, t_flag *flag)
{
	long		nb;
	int			len;

	nb = va_arg(*arg, long);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag(nb, flag);
	write_padleft_int(flag, len, nb);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_int(nb);
	if (flag->neg && flag->width)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
