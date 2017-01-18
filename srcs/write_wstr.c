/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 09:59:20 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 13:04:18 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_wstr(va_list *arg, t_flag *flag)
{
	wchar_t		*wstr;
	int			len;
	int			isnull;

	isnull = 0;
	wstr = va_arg(*arg, wchar_t*);
	len = (flag->precision) ? nlen_wstr(wstr, flag->precision) : len_wstr(wstr);
	if (wstr == NULL)
	{
		isnull = 1;
		len = (flag->precision) ? ft_strnlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
	if (!(flag->prec && flag->precision == 0) && isnull == 0)
		ft_putnwstr(wstr, len);
	else if (isnull == 1)
		ft_putnstr("(null)", len);
	if (flag->neg && flag->width)
		write_blank(flag->width, len);
	return ((flag->width) > len ? flag->width : len);
}
