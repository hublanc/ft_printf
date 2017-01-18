/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:49:49 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/15 17:50:30 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_blank(int width, int len)
{
	int		n;

	n = width - len;
	while (n-- > 0)
		ft_putchar(' ');
}

void	write_zero(int width, int len)
{
	int		n;

	n = width - len;
	while (n-- > 0)
		ft_putchar('0');
}
