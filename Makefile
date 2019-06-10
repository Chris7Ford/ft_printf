# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chford <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/09 12:12:47 by chford            #+#    #+#              #
#    Updated: 2019/06/10 15:07:13 by chford           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c length.c string_arithmetic.c \
ft_printf.h test.c csp.c \
new_float.c test2.c \
digits.c ft_ulltoa.c octal.c \
dispatch.c get_value.c octal_helpers.c \
divide_string.c helpers.c print_string.c unsigned.c \
flags.c hex.c var_handling.c \
ft_lltoa.c hex_helpers.c spec.c \
float_bits.c float_helpers.c digit_prefix.c \
hex_helpers2.c more_float_helpers.c
SRCL = libft/ft_lstmap.c libft/ft_putendl_fd.c libft/ft_striter.c libft/ft_strrchr.c libft/ft_atoi.c libft/ft_lstnew.c libft/ft_putnbr.c libft/ft_striteri.c libft/ft_strsplit.c libft/ft_bzero.c libft/ft_memalloc.c libft/ft_putnbr_fd.c libft/ft_strjoin.c libft/ft_strstr.c libft/ft_isalnum.c libft/ft_memccpy.c libft/ft_putstr.c libft/ft_strlcat.c libft/ft_strsub.c libft/ft_isalpha.c libft/ft_memchr.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_strtrim.c libft/ft_isascii.c libft/ft_memcmp.c libft/ft_strcat.c libft/ft_strmap.c libft/ft_tolower.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strchr.c libft/ft_strmapi.c libft/ft_toupper.c libft/ft_isprint.c libft/ft_memdel.c libft/ft_strclr.c libft/ft_strncat.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_lstadd.c libft/ft_memset.c libft/ft_strcpy.c libft/ft_strncpy.c libft/ft_lstdel.c libft/ft_putchar.c libft/ft_strdel.c libft/ft_strnequ.c libft/ft_lstdelone.c libft/ft_putchar_fd.c libft/ft_strdup.c libft/ft_strnew.c libft/ft_lstiter.c libft/ft_putendl.c libft/ft_strequ.c libft/ft_strnstr.c libft/ft_lstpush.c libft/ft_absval.c libft/ft_isspace.c libft/ft_max.c libft/ft_min.c libft/print_hex_ulong_fd.c libft/ft_putstr_constrain_fd.c libft/print_hex_ulong_length.c libft/ft_strjoin_free.c libft/ft_prepend_char.c libft/ft_islower.c libft/ft_isupper.c libft/ft_strjoin_char.c libft/ft_isupper.c libft/ft_islower.c libft/get_char_array_len.c libft/ft_join_str_array.c libft/free_string_array.c

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC)
	gcc -c $(FLAGS) $(SRCL)
	ar rc libftprintf.a *.o
	ranlib libftprintf.a
clean:
	/bin/rm -f *.o
	/bin/rm -f libft/*.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
