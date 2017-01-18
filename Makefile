# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hublanc <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 12:22:37 by hublanc           #+#    #+#              #
#    Updated: 2016/12/20 19:10:42 by hublanc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILEC	=	ft_printf.c parser.c write_str.c write_int.c write_pointer.c write_octal.c \
			write_unsigned_int.c write_wstr.c write_long_int.c write_unsigned_long_octal.c \
			write_unsigned_long_int.c write_upper_hexa.c write_lower_hexa.c write_chr.c \
			write_wchr.c write_dint.c write_percent.c get_type.c tools_str.c tools_padding.c \
			tools_int.c tools_uint.c tools_wstr.c write_undefined.c write_binary.c
LIBC	=	ft_memset.c ft_bzero.c ft_memcpy.c ft_strlen.c ft_strdup.c ft_strcmp.c ft_strcpy.c ft_strncpy.c\
			ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strncmp.c\
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_putchar.c ft_putstr.c ft_putendl.c\
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c ft_strsplit.c\
			ft_strtrim.c ft_strjoin.c ft_strsub.c ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strmap.c ft_striter.c\
			ft_striteri.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c\
			ft_lstadd.c ft_lstiter.c ft_lstmap.c
OBJ		=	$(FILEC:.c=.o)
OBJLIB	=	$(LIBC:.c=.o)
SRCDIR	=	./srcs/
INCLUDE	=	./includes/
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
LIBINC	=	./libft/includes/
LIBNAME	=	./libft/
NAME	=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)

%.o: $(SRCDIR)%.c $(INCLUDE)
	$(CC) -o $@ -c $< $(FLAGS) -I $(INCLUDE)

%.o: $(LIBNAME)%.c $(LIBINC)
	$(CC) -o $@ -c $< $(FLAGS) -I $(LIBINC)

clean:
	rm -f $(OBJ) $(OBJLIB)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
