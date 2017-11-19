NAME=libftinput_reader.a

SRC_D:=src
OBJ_D:=obj
INC_D:=inc
LIB_D:=..

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

INC:=-I $(INC_D)

INCLUDES:=$(INC)

ITEM:=\
	ft_read_input.o\
	ft_handle_char.o\
	ft_handle_del.o\
	ft_handle_non_char.o\
	ft_handle_vert.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

VPATH:=$(SRC_D):$(INC_D)

RANLIB:=ranlib
MKDIR:=mkdir -p

include libs.mk

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

$(OBJ_D)/%.o: %.c
	$(MKDIR) $(OBJ_D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(RM) -r $(OBJ_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all
