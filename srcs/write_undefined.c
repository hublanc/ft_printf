/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_undefined.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:16:03 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/19 18:26:12 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_undefined(char c, t_flag *flag)
{
	int		len;

	len = 1;
	if (flag->width && !flag->zero && !flag->neg)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
	ft_putchar(c);
	if (flag->width && flag->neg)
		write_blank(flag->width, len);
	return (flag->width > len ? flag->width : len);
}
