# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akarasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 09:02:12 by akarasso          #+#    #+#              #
#    Updated: 2018/05/06 09:03:13 by akarasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

HEADERS	= ./includes 

SOURCES	= ./srcs/convert.c			./srcs/ft_printf.c			./srcs/color/pf_get_color.c			\
	./srcs/color/pf_parser_color.c		./srcs/conversion/pf_b.c		./srcs/conversion/pf_c.c			\
	./srcs/conversion/pf_cc.c		./srcs/conversion/pf_d.c		./srcs/conversion/pf_mod.c			\
	./srcs/conversion/pf_o.c		./srcs/conversion/pf_p.c		./srcs/conversion/pf_s.c			\
	./srcs/conversion/pf_ss.c		./srcs/conversion/pf_u.c		./srcs/conversion/pf_x.c			\
	./srcs/parser/parser.c			./srcs/utils/pf_atoi.c			./srcs/utils/pf_calc_field_len.c		\
	./srcs/utils/pf_field.c			./srcs/utils/pf_itoa_base.c		./srcs/utils/pf_max.c				\
	./srcs/utils/pf_nbr_len.c		./srcs/utils/pf_print.c			./srcs/utils/pf_printw.c			\
	./srcs/utils/pf_strcpy.c		./srcs/utils/pf_strncmp.c		./srcs/utils/pf_va_arg.c			\
	./srcs/utils/pf_wcharlen.c		./srcs/utils/pf_wstrcpy.c		./srcs/utils/pf_wstrlen.c		

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	ar rcs $(NAME) $(OBJ)

so	: $(OBJ)
	$(CC) -fPIC $(CFLAGS) $(SOURCES) -shared -I$(HEADERS)

clean	: 
	rm -f $(OBJ)

re	: fclean all

fclean	: clean
	rm -f $(NAME)

