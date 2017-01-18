/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:53:29 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 13:40:16 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_ui(uintmax_t nb, char *str, int base)
{
	int		c;

	if (nb / base > 0)
		get_ui(nb / base, str, base);
	c = nb % base;
	write(1, &str[c], 1);
}

int			get_len_ui(uintmax_t nb, int base)
{
	int		len;

	len = 0;
	while (nb /= base)
		len++;
	return (len + 1);
}

int			get_len_flag_ui(uintmax_t nb, t_flag *flag, int base)
{
	int			len;

	len = get_len_ui(nb, base);
	if (flag->precision > len)
		len += flag->precision - len;
	if (flag->ht)
	{
		if (base == 16 && nb > 0)
			len += 2;
		if (base == 8 && nb > 0)
			len++;
	}
	if (flag->prec && flag->precision == 0 && nb == 0)
		len = (flag->ht && base == 8) ? 1 : 0;
	return (len);
}

void		write_padleft_uint(t_flag *flag, int len, uintmax_t nb, int type)
{
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->ht || type == 4)
	{
		if ((type == 1 && len != 0 && nb > 0) || type == 4)
			ft_putstr("0x");
		if (type == 2 && len != 0 && nb > 0)
			ft_putstr("0X");
		if (type == 3)
			ft_putstr("0");
	}
	if (flag->zero && flag->width && !flag->neg && !flag->precision)
		write_zero(flag->width, len);
	else if (flag->precision)
	{
		if (type == 1 || type == 2 || type == 4)
			write_zero(flag->precision, get_len_ui(nb, 16));
		if (type == 3)
			write_zero(flag->precision, get_len_ui(nb, 8));
		if (type == 0)
			write_zero(flag->precision, get_len_ui(nb, 10));
		if (type == 5)
			write_zero(flag->precision, get_len_ui(nb, 2));
	}
}
