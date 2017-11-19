NAME:=libftmem.a

GREEN:="\033[32m"
ORANGE:="\033[33m"
RED:="\033[31m"
CLEAR:="\033[0m"

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -O2

MKDIR:=mkdir -p
RANLIB:=ranlib

OBJ_D:=obj
INC_D:=inc
LIB_D:=..

INC:=-I $(INC_D)

INCLUDES:=\
	$(INC)

ITEM:=\
	ft_bzero.o\
	ft_memalloc.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_memcpy.o\
	ft_memdel.o\
	ft_memdup.o
OBJ:=$(addprefix ./obj/, $(ITEM))

VPATH:=src:inc

HEADER:=ft_mem.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@echo ${GREEN}Built $(NAME)${CLEAR}

./${OBJ_D}/%.o: %.c $(HEADERS)
	@$(MKDIR) $(OBJ_D)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@echo ${ORANGE}Cleaning $(NAME)${CLEAR}
	@$(RM) -r $(OBJ_D)

fclean: clean
	@echo ${RED}Full cleaning $(NAME)${CLEAR}
	@$(RM) $(NAME)

re: fclean all

