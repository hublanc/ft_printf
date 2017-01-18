/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:41:17 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/19 16:36:18 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_wchr(va_list *arg, t_flag *flag)
{
	wchar_t			c;
	int				len;

	c = (wchar_t)va_arg(*arg, wint_t);
	len = len_wchr(c);
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
	ft_putwchar(c);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
