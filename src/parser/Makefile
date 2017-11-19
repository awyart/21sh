NAME:=libftparser.a
CC:=gcc

MKDIR:=mkdir -p

CFLAGS:=-Wall -Wextra -Werror

INC_D:=inc
SCR_D:=src
LIB_D:=../../lib
OBJ_D:=obj

ITEM:=\
	init.o 
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

INCLUDES = -I $(INC_D)

include ../../libs.mk

LIBRARIES += -L ./ -lftparser

VPATH:=src:inc

TET = test.c 

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_D)/%.o:%.c 
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(RM) -r $(OBJ_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test : all
	$(CC) $(CFLAGS) $(TET) $(INCLUDES) $(LIBRARIES)