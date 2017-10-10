NAME = minishell
HEAD = includes/minishell.h

ifeq ($(MORE), yes)
	FLAG = -Werror -Wall -Wextra 
else
	FLAG = -g3
endif

PRINTF_DIR = libft/ft_printf
LIBFT_DIR = libft
PRINTF_LIB = libftprintf.a
LIBFT_LIB = libft.a

LIB = $(LIBFT_DIR)/$(LIBFT_LIB) \
	$(PRINTF_DIR)/$(PRINTF_LIB)

IPATH = includes
MKFILE = Makefile

SRC1 = *.c

SRC = $(patsubst %,srcs/%,$(SRC1)) \
		$(patsubst %,srcs/builtin/%,$(SRC1)) \
		$(patsubst %,srcs/cmd/%,$(SRC1)) \
		$(patsubst %,srcs/history/%,$(SRC1)) \
		$(patsubst %,srcs/parser/%,$(SRC1)) \
		$(patsubst %,srcs/signal/%,$(SRC1)) \
		$(patsubst %,srcs/utility/%,$(SRC1)) \
		$(patsubst %,srcs/init/%,$(SRC1)) \
		$(patsubst %,srcs/l_parser/%,$(SRC1)) \

#FLAG += -lncurses
#FLAG += -fsanitize=address
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(HEAD) $(MKFILE)
	@echo "Compiling \033[92m$(LIB)\033[0m..."
	@make -C $(LIBFT_DIR)/
	@make -C $(PRINTF_DIR)/
	@gcc $(SRC) $(FLAG) -I $(IPATH) $(LIB) -o $(NAME)
	@echo "$(NAME) compilation:\033[92m OK\033[0m"

clean:
	@echo "Deleting:\033[33m $(PRINTF_LIB), $(LIBFT_LIB) and *.o\033[0m"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR)/ clean
	@make -C $(PRINTF_DIR)/ clean

fclean: clean
	@echo "Deleting:\033[33m $(NAME)\033[0m"
	@echo "Deleting:\033[33m $(PRINTF_LIB), $(LIBFT_LIB) and *.o\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR)/ fclean
	@make -C $(PRINTF_DIR)/ fclean

re: fclean all

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push

.PHONY: clean fclean re git gitp
