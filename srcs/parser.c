/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:44:33 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 16:58:08 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_option(char **str, t_flag *flag, va_list *arg)
{
	if (**str != '0' && (ft_isdigit(**str) || **str == '*'))
		check_width(str, flag, arg);
	if (**str == '.')
		check_preci(str, flag, arg);
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
		check_length(str, flag, arg);
	if (**str == '#' || **str == '0' || **str == '-'
			|| **str == '+' || **str == ' ')
		check_flag(str, flag, arg);
}

void		check_flag(char **str, t_flag *flag, va_list *arg)
{
	while (**str == '#' || **str == '0' || **str == '-'
			|| **str == '+' || **str == ' ')
	{
		if (**str == '#')
			flag->ht = 1;
		if (**str == '0')
			flag->zero = 1;
		if (**str == '-')
			flag->neg = 1;
		if (**str == '+')
			flag->pos = 1;
		if (**str == ' ')
			flag->space = 1;
		(*str)++;
	}
	check_option(str, flag, arg);
}

void		check_width(char **str, t_flag *flag, va_list *arg)
{
	int		width;

	width = 0;
	flag->width = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '*')
	{
		width = va_arg(*arg, int);
		if (width < 0)
			flag->neg = 1;
		flag->width = width < 0 ? -width : width;
		(*str)++;
	}
	check_option(str, flag, arg);
}

void		check_preci(char **str, t_flag *flag, va_list *arg)
{
	int		precision;

	precision = 0;
	while (**str == '.')
	{
		flag->prec = 1;
		(*str)++;
		flag->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
		if (**str == '*')
		{
			(*str)++;
			if ((precision = va_arg(*arg, int)) >= 0)
				flag->precision = precision;
			else if (precision < 0)
				flag->prec = 0;
		}
	}
	check_option(str, flag, arg);
}

void		check_length(char **str, t_flag *flag, va_list *arg)
{
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h' && flag->e_length < 3)
			flag->e_length = hh;
		else if (flag->e_length < 2)
			flag->e_length = h;
	}
	if (**str == 'l')
	{
		if (*(*str + 1) == 'l' && flag->e_length < 5)
			flag->e_length = ll;
		else if (flag->e_length < 4)
			flag->e_length = l;
	}
	if (**str == 'j' && flag->e_length < 6)
		flag->e_length = j;
	if (**str == 'z')
		flag->e_length = z;
	if (flag->e_length)
		(*str)++;
	if (flag->e_length == hh || flag->e_length == ll)
		(*str)++;
	check_option(str, flag, arg);
}
