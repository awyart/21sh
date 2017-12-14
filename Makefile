NAME:=21sh
CC:=gcc

RM:=/bin/rm -f
MKDIR:=mkdir -p

ifeq ($(DEBUG),yes)
CFLAGS:=-g3 -fsanitize=address
else
CFLAGS:=-Wall -Wextra -Werror
endif

INC_D:=inc
SCR_D:=src
LIB_D:=lib
OBJ_D:=obj

INCLUDES = -I inc \
		-I lib/ft_printf/inc \
		-I lib/libft/inc \
		-I lib/ft_dlist/inc \
		-I lib/ft_autocomp/inc

LIBRARIES = -L lib/ft_printf -lftprintf \
			-L lib/libft -lft \
			-L lib/ft_dlist -lftdlist \
			-L lib/ft_autocomp -lautocompletion \
			-lcurses

ITEM = main.o \
		envdup.o \
		getterm.o \
		ft_terms.o \
		ft_terms_get.o\
		signal.o \
		prompt.o \
		ft_handle_char.o\
		ft_handle_del.o\
		ft_handle_non_char.o\
		ft_handle_arrow.o\
		ft_read_input.o \
		refresh_line.o \
		mvcursor.o \
		info_cursor.o \
		lexer.o \
		print_input.o \
		token.o \
		detect.o \
		htok.o \
		heredoc.o \
		parser.o \
		handle_bslash.o\
		handle_ctrl.o\
		ft_handle_arrow2.o\
		process.o \
		utility.o \
		launchjob.o \
		execution.o

OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

vpath %.c src \
		src/env \
		src/signal \
		src/prompt \
		src/input_reader \
		src/lexer \
		src/parser \
		src/job \
		src/execution

vpath %.h inc ../libft/inc

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C lib/libft
	@$(MAKE) -C lib/ft_printf
	@$(MAKE) -C lib/ft_dlist
	@$(MAKE) -C lib/ft_autocomp
	@$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)
	@echo  "it's done"

./${OBJ_D}/%.o: %.c 
	@$(MKDIR) $(OBJ_D)
	@$(CC) $(CFLAGS) -c -o $@ $<  $(INCLUDES)

clean:
	@$(MAKE) -C lib/ft_printf clean
	@$(MAKE) -C lib/libft clean
	@$(MAKE) -C lib/ft_dlist clean
	@$(MAKE) -C lib/ft_autocomp clean
	@$(RM) -r $(OBJ_D)
	@echo "it's clean"

fclean: clean
	@$(MAKE) -C lib/ft_printf fclean
	@$(MAKE) -C lib/libft fclean
	@$(MAKE) -C lib/ft_dlist fclean
	@$(MAKE) -C lib/ft_autocomp fclean
	@$(RM) $(NAME)
	@echo "it's fclean"

re: fclean all
