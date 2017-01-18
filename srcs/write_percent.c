/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:20:16 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 18:13:19 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			write_percent(va_list *arg, t_flag *flag)
{
	int		len;

	len = 1;
	if (flag->width && !flag->zero && !flag->neg)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
	ft_putchar('%');
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
