# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 14:49:46 by rkhilenk          #+#    #+#              #
#    Updated: 2018/03/15 14:49:48 by rkhilenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   lem-in

SRC         =   main.c \
				reader.c \
				list_handler.c \
				reader_rooms.c \
				assist1.c \

OBJ         =   $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR     =   ./src/
OBJ_DIR     =   ./obj/
INC_DIR     =   ./inc/
LIB_DIR     =   ./lib/

LIB         =   $(LIBFT_DIR)libft.a
LIBFT_DIR   =   $(LIB_DIR)libft/
LIBFT_INC   =   $(LIBFT_DIR)includes/
LIBFT_FLAGS =   -lft -L $(LIBFT_DIR)

LINK_FLAGS  =   $(LIBFT_FLAGS)

HEAD_FLAGS  =   -I $(INC_DIR) -I $(LIBFT_INC)

CC_FLAGS    =   -Wall -Wextra -Werror

CC          =   gcc

FRAME_FLAGS = 

all : $(NAME)
$(NAME) : $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME) $(FRAME_FLAGS)
$(OBJ): | $(OBJ_DIR)
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
$(LIB):
	make -C $(LIBFT_DIR)
clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)
fclean : clean
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)
re : fclean all
vpath %.c $(SRC_DIR)
.PHONY: all fclean clean re 
main: all
	@./$(NAME)
