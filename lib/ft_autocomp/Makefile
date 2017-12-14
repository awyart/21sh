NAME = libautocompletion.a

SRC_D:=src
OBJ_D:=obj
INC_D:=inc
LIB_D:=..

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
CFLAGS += -g
#CFLAG += -fsanitize=address

INC:=-I $(INC_D)
INCLUDES:=$(INC)

O_FILES := \
	add_branch_to_input.o\
	add_word_to_tree.o\
	history_to_tree.o\
	leven.o\
	list_to_lev_tree.o\
	new_hlist.o\
	new_lev_node.o\
	print_lev_tree.o\
	read_stock_input.o\
	search_thru_history.o\
	history_handler.o\
	tree_to_dlist.o\
	hlist_free.o\
	free_str.o
C_FILES := \
	add_branch_to_input.c\
	add_word_to_tree.c\
	history_to_tree.c\
	leven.c\
	list_to_lev_tree.c\
	new_hlist.c\
	new_lev_node.c\
	print_lev_tree.c\
	read_stock_input.c\
	search_thru_history.c\
	history_handler.c\
	tree_to_dlist.c\
	hlist_free.c\
	free_str.c
OBJ := $(addprefix $(OBJ_D)/, $(O_FILES))
SRC := $(addprefix $(SRC_D)/, $(C_FILES))
VPATH :=$(SRC_D):$(INC_D)

include libs.mk

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
#	@gcc $(SRC) ../ft_printf/libftprintf.a ../libft/libft.a
	@echo "libautocompletion.a built"

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@echo "[autocomp] Deleting:\033[33m *.o\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "[autocomp] Deleting:\033[33m $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push

.PHONY: clean fclean re git gitp
