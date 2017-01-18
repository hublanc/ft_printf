/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:14:36 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 13:37:29 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_binary(va_list *arg, t_flag *flag)
{
	uintmax_t		nb;
	int				len;

	nb = va_arg(*arg, uintmax_t);
	if (flag->prec)
		flag->zero = 0;
	len = get_len_flag_ui(nb, flag, 2);
	write_padleft_uint(flag, len, nb, 5);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_ui(nb, "01", 2);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
