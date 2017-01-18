/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:04:27 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 16:53:56 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		get_utype(va_list *arg, t_flag *flag)
{
	uintmax_t		res;

	res = va_arg(*arg, uintmax_t);
	if (flag->e_length == hh)
		return ((unsigned char)res);
	if (flag->e_length == h)
		return ((unsigned short)res);
	if (flag->e_length == l)
		return ((unsigned long)res);
	if (flag->e_length == ll)
		return ((unsigned long long)res);
	if (flag->e_length == j)
		return (res);
	if (flag->e_length == z)
		return ((size_t)res);
	return ((unsigned int)res);
}

intmax_t		get_type(va_list *arg, t_flag *flag)
{
	intmax_t		res;

	res = va_arg(*arg, intmax_t);
	if (flag->e_length == hh)
		return ((signed char)res);
	if (flag->e_length == h)
		return ((short)res);
	if (flag->e_length == l)
		return ((long)res);
	if (flag->e_length == ll)
		return ((long long)res);
	if (flag->e_length == j)
		return (res);
	if (flag->e_length == z)
		return ((size_t)res);
	return ((int)res);
}
