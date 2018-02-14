NAME:=21sh
CC:=gcc

RM:=/bin/rm -f
MKDIR:=mkdir -p

ifeq ($(DEBUG),yes)
CFLAGS:=-g3 -fsanitize=address
else
CFLAGS:= -O2 -Wall -Wextra -Werror
endif
INC_D:=inc
SCR_D:=src
LIB_D:=lib
OBJ_D:=obj
HEAD =$(INC_D)/header.h

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
		lexer.o \
		print_input.o \
		token.o \
		detect.o \
		htok.o \
		parser.o \
		handle_bslash.o\
		process.o \
		utility.o \
		launchjob.o \
		execution.o \
		cd.o \
		echo.o \
		env.o \
		exit.o \
		setenv.o \
		unsetenv.o \
		build_in.o \
		cmd.o \
		get_str_in_quotes.o \
		spec_char.o \
		add_char.o \
		del_char.o \
		mv.o \
		buf.o\
		read.o \
		refresh_line.o \
		visu.o \
		hist.o \

OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

vpath %.c src \
		src/env \
		src/signal \
		src/prompt \
		src/lexer \
		src/parser \
		src/job \
		src/execution \
		src/buildin \
		src/str_format \
		src/reader \

vpath %.h inc ../libft/inc

all: $(NAME)

$(NAME): $(OBJ) $(HEAD) Makefile
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

git :
	@git add .
	@git commit -m "${MSG}"

gitp : fclean git
	git push
