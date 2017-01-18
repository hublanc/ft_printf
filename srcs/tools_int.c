/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:52:12 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/16 15:50:47 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_int(intmax_t nb)
{
	int			c;
	uintmax_t	n;

	if (nb < 0)
		n = -nb;
	else
		n = nb;
	if (n / 10 > 0)
		get_int(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

int			get_len_flag(intmax_t nb, t_flag *flag)
{
	int		len;

	len = get_len(nb);
	if (flag->precision > len)
		len += flag->precision - len;
	if (flag->pos && nb >= 0)
		len++;
	if (flag->space && !flag->pos && nb >= 0)
		len++;
	if (nb < 0)
		len++;
	if (flag->prec && flag->precision == 0 && nb == 0)
		len = flag->space ? 1 : 0;
	return (len);
}

int			get_len(intmax_t nb)
{
	int			len;
	uintmax_t	n;

	len = 0;
	if (nb < 0)
		n = -nb;
	else
		n = nb;
	while (n /= 10)
		len++;
	return (len + 1);
}

void		write_padleft_int(t_flag *flag, int len, intmax_t nb)
{
	if (flag->space && !flag->pos && nb >= 0)
		ft_putchar(' ');
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->pos && nb >= 0 && len != 0)
		ft_putchar('+');
	if (nb < 0 && len != 0)
		ft_putchar('-');
	if (flag->zero && flag->width && !flag->neg && !flag->precision)
		write_zero(flag->width, len);
	else if (flag->precision)
		write_zero(flag->precision, get_len(nb));
}
