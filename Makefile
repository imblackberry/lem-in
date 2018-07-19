#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblokha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/03 11:40:29 by vblokha           #+#    #+#              #
#    Updated: 2018/07/03 11:40:31 by vblokha          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = lem_in.c set_farm.c check_data.c check_level_2.c new_structs.c adding.c free_farm.c analize.c searching.c

SRCDIR = sources/

OBJDIR = objects/

OBJ =  $(addprefix $(OBJDIR), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFTPRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(LIBFTPRINTF) $(OBJDIR) $(OBJ)
	@gcc $(OBJ) ft_printf/libftprintf.a -o $(NAME)
	@echo project DONE

$(LIBFTPRINTF):
	@echo make ft_printf
	make -C ft_printf

$(OBJDIR):
	@mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	gcc $(FLAGS) -I headers/lem-in.h -c $< -o $@

comp:
	@gcc -g $(FLAGS) $(addprefix $(SRCDIR), $(SRC)) ft_printf/$(LIBFTPRINTF) -I headers/lem-in.h -o debug

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	@make clean -C ft_printf
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all