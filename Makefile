NAME:=21sh
CC:=gcc

RM:=/bin/rm -f
MKDIR:=mkdir -p

CFLAGS:=-Wall -Wextra -Werror

INC_D:=inc
SCR_D:=src
LIB_D:=lib
OBJ_D:=obj

INCLUDES = -I inc -I lib/ft_printf/inc -I lib/libft/inc

LIBRARIES = -L lib/ft_printf -lftprintf -L lib/libft -lft 	-lcurses

ITEM = main.o \
		envdup.o \
		getterm.o

OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

vpath %.c src src/env
vpath %.h inc

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C lib/ft_printf
	@$(MAKE) -C lib/libft
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)

./${OBJ_D}/%.o: %.c 
	@$(MKDIR) $(OBJ_D)
	@$(CC) $(CFLAGS) -c -o $@ $<  $(INCLUDES)

clean:
	@$(MAKE) -C lib/ft_printf clean
	@$(MAKE) -C lib/libft clean
	$(RM) -r $(OBJ_D)

fclean: clean
	@$(MAKE) -C lib/ft_printf fclean
	@$(MAKE) -C lib/libft fclean
	$(RM) $(NAME)

re: fclean all
