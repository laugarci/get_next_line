# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:19:32 by laugarci          #+#    #+#              #
#    Updated: 2022/11/30 16:45:04 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

HEADER	= get_next_line.h

INCLUDE = -I ./

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
AR		= ar -rcs

SRC_FILES	= get_next_line.c \
			  get_next_line_utils.c \

SRC_OBJ		= $(SRC_FILES:.c=.o)

SRC_DEPS	= $(SRC_FILES:.c=.d)

all:	$(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compiling $<..."

$(NAME) : $(SRC_OBJ)
	@$(AR) $(NAME) $(SRC_OBJ)
	@echo Library compiled!

clean:
	@$(RM) $(SRC_OBJ) $(SRC_DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm:
	$(NORM)

-include $(SRC_DEPS)

.PHONY: all clean fclean re norm
