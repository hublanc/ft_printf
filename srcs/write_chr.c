/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:16:47 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 16:53:07 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_chr(va_list *arg, t_flag *flag)
{
	unsigned char	c;
	int				len;

	len = 1;
	if (flag->e_length == l)
		return (write_wchr(arg, flag));
	c = (unsigned char)va_arg(*arg, int);
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
	write(1, &c, 1);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
