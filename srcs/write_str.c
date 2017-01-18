/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:28:17 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 16:52:47 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_str(va_list *arg, t_flag *flag)
{
	char	*str;
	int		len;
	int		isnull;

	isnull = 0;
	if (flag->e_length == l)
		return (write_wstr(arg, flag));
	str = va_arg(*arg, char*);
	len = (flag->precision) ? ft_strnlen(str, flag->precision) : ft_strlen(str);
	if (str == NULL)
	{
		isnull = 1;
		len = (flag->precision) ? ft_strnlen("(null)", flag->precision) : 6;
	}
	if (flag->prec && flag->precision == 0)
		len = 0;
	write_padleft_str(flag, len);
	if (!(flag->prec && flag->precision == 0) && isnull == 0)
		ft_putnstr(str, len);
	else if (isnull == 1)
		ft_putnstr("(null)", len);
	if (flag->neg && flag->width)
		write_blank(flag->width, len);
	return ((flag->width > len) ? flag->width : len);
}
