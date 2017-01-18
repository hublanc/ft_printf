/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hublanc <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:13:27 by hublanc           #+#    #+#             */
/*   Updated: 2016/12/20 16:47:31 by hublanc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdint.h>
# include "../libft/includes/libft.h"

typedef struct		s_flag
{
	int				precision;
	int				prec;
	int				neg;
	int				pos;
	int				space;
	int				ht;
	int				zero;
	int				width;
	enum
	{
		none,
		h,
		hh,
		l,
		ll,
		j,
		z
	}				e_length;
}					t_flag;

int					ft_printf(const char *format, ...);
int					parser(char **format, t_flag *flag, va_list *arg);
int					check_specifier(char **format, t_flag *flag, va_list *arg);
int					write_str(va_list *arg, t_flag *flag);
int					write_int(va_list *arg, t_flag *flag);
int					write_dint(va_list *arg, t_flag *flag);
int					write_pointer(va_list *arg, t_flag *flag);
int					write_octal(va_list *arg, t_flag *flag);
int					write_unsigned_long_octal(va_list *arg, t_flag *flag);
int					write_unsigned_int(va_list *arg, t_flag *flag);
int					write_unsigned_long_int(va_list *arg, t_flag *flag);
int					write_long_int(va_list *arg, t_flag *flag);
int					write_wstr(va_list *arg, t_flag *flag);
int					write_lower_hexa(va_list *arg, t_flag *flag);
int					write_upper_hexa(va_list *arg, t_flag *flag);
int					write_chr(va_list *arg, t_flag *flag);
int					write_wchr(va_list *arg, t_flag *flag);
int					write_percent(va_list *arg, t_flag *flag);
int					write_undefined(char c, t_flag *flag);
int					write_binary(va_list *arg, t_flag *flag);

void				check_option(char **str, t_flag *flag, va_list *arg);
void				check_flag(char **str, t_flag *flag, va_list *arg);
void				check_width(char **str, t_flag *flag, va_list *arg);
void				check_preci(char **str, t_flag *flag, va_list *arg);
void				check_length(char **str, t_flag *flag, va_list *arg);

uintmax_t			get_utype(va_list *arg, t_flag *flag);
intmax_t			get_type(va_list *arg, t_flag *flag);
void				reinit_flag(t_flag *flag);
void				ft_putnstr(char *str, int n);
int					ft_strnlen(char *str, int n);
int					len_wchr(wchar_t c);
int					len_wstr(wchar_t *s);
int					nlen_wstr(wchar_t *s, int n);
void				ft_putwchar(wchar_t c);
void				ft_putnwstr(wchar_t *s, int n);
void				write_blank(int width, int strlen);
void				write_zero(int width, int strlen);
void				get_int(intmax_t nb);
int					get_len(intmax_t nb);
int					get_len_flag(intmax_t nb, t_flag *flag);
void				get_ui(uintmax_t nb, char *str, int base);
int					get_len_ui(uintmax_t nb, int base);
int					get_len_flag_ui(uintmax_t nb, t_flag *flag, int base);
void				write_padleft_int(t_flag *flag, int len, intmax_t nb);
void				write_padleft_uint(t_flag *flag, int len,
					uintmax_t nb, int type);
void				write_padleft_str(t_flag *flag, int len);

#endif
