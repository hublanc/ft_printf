/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 12:46:34 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 13:06:25 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putwchar(wchar_t c)
{
	if (c <= 0x7F)
		ft_putchar(c);
	else if (c <= 0x7FF)
	{
		ft_putchar((c >> 6) + 0xC0);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_putchar((c >> 12) + 0xE0);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
	else
	{
		ft_putchar((c >> 18) + 0xF0);
		ft_putchar(((c >> 12) & 0x3F) + 0x80);
		ft_putchar(((c >> 6) & 0x3F) + 0x80);
		ft_putchar((c & 0x3F) + 0x80);
	}
}

int			len_wchr(wchar_t c)
{
	int		len;

	len = 0;
	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else
		len = 4;
	return (len);
}

void		ft_putnwstr(wchar_t *s, int n)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (len_wchr(s[i]) > n)
			break ;
		n -= len_wchr(s[i]);
		ft_putwchar(s[i++]);
	}
}

int			nlen_wstr(wchar_t *s, int n)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[i] != '\0' && n > 0)
	{
		if (len_wchr(s[i]) > n)
			break ;
		n -= len_wchr(s[i]);
		len += len_wchr(s[i++]);
	}
	return (len);
}

int			len_wstr(wchar_t *s)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		len += len_wchr(s[i++]);
	return (len);
}
