/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:47:36 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/18 18:32:05 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (n-- > 0 && str[i] != '\0')
		ft_putchar(str[i++]);
}

int		ft_strnlen(char *str, int n)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while ((n-- > 0) && (str[i] != '\0'))
		i++;
	return (i);
}

void	write_padleft_str(t_flag *flag, int len)
{
	if (flag->width && !flag->neg && !flag->zero)
		write_blank(flag->width, len);
	if (flag->width && flag->zero && !flag->neg)
		write_zero(flag->width, len);
}
