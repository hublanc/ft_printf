/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:17:43 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/19 17:42:14 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_pointer(va_list *arg, t_flag *flag)
{
	void			*ptr;
	uintmax_t		nb;
	int				len;

	ptr = va_arg(*arg, void*);
	nb = (unsigned long)ptr;
	len = get_len_flag_ui(nb, flag, 16);
	if (!flag->ht)
		len += 2;
	write_padleft_uint(flag, len, nb, 4);
	if (!(flag->prec && flag->precision == 0 && nb == 0))
		get_ui(nb, "0123456789abcdef", 16);
	if (flag->neg && flag->width)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
