/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:03:23 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 19:13:45 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reinit_flag(t_flag *flag)
{
	flag->precision = 0;
	flag->prec = 0;
	flag->neg = 0;
	flag->pos = 0;
	flag->space = 0;
	flag->ht = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->e_length = 0;
}

int			check_specifier(char **format, t_flag *flag, va_list *arg)
{
	static int	(*f[])(va_list*, t_flag*) = {write_str, write_wstr,
		write_pointer, write_dint, write_long_int, write_int, write_octal,
		write_unsigned_long_octal, write_unsigned_int, write_unsigned_long_int,
		write_lower_hexa, write_upper_hexa, write_chr, write_wchr,
		write_percent, write_binary, 0};
	static char	spec[] = {'s', 'S', 'p', 'd', 'D', 'i', 'o', 'O', 'u', 'U',
		'x', 'X', 'c', 'C', '%', 'b', 0};
	int			i;
	int			ret;

	i = 0;
	while (spec[i] != **format && spec[i])
		i++;
	if (**format != '\0' && spec[i] == **format)
	{
		ret = f[i](arg, flag);
		(*format)++;
		return (ret);
	}
	if (**format != '\0')
	{
		(*format)++;
		return (write_undefined(*(*format - 1), flag));
	}
	return (0);
}

int			parser(char **format, t_flag *flag, va_list *arg)
{
	int		ret;

	ret = 0;
	while (**format)
	{
		if (**format == '%')
		{
			reinit_flag(flag);
			(*format)++;
			check_option(format, flag, arg);
			ret += check_specifier(format, flag, arg);
		}
		else if (**format != '\0')
		{
			ft_putchar(**format);
			(*format)++;
			ret++;
		}
	}
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg;
	t_flag		*flag;
	int			ret;

	ret = 0;
	flag = ft_memalloc(sizeof(t_flag));
	va_start(arg, format);
	ret = parser((char**)&format, flag, &arg);
	va_end(arg);
	ft_memdel((void**)&flag);
	return (ret);
}
