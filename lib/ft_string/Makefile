NAME:=libftstring.a

GREEN:="\033[32m"
ORANGE:="\033[33m"
RED:="\033[31m"
CLEAR:="\033[0m"

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
CFLAGS+=-O2

MKDIR:=mkdir -p
RANLIB:=ranlib

OBJ_D:=obj
INC_D:=inc
LIB_D:=..

INC:=-I $(INC_D)

INCLUDES:=\
	$(INC)

ITEM:=\
	ft_atoi.o\
	ft_atol.o\
	ft_is.o\
	ft_getnumber.o\
	ft_ltobuf.o\
	ft_pathjoin.o\
	ft_putblank.o\
	ft_putstr_fd.o\
	ft_split.o\
	ft_strappend.o\
	ft_strcat.o\
	ft_strchr.o\
	ft_strclearchars.o\
	ft_strclr.o\
	ft_strcmp.o\
	ft_strcpy.o\
	ft_strdel.o\
	ft_strdivide.o\
	ft_strdup.o\
	ft_strequ.o\
	ft_strforeach.o\
	ft_strindex.o\
	ft_striter.o\
	ft_striteri.o\
	ft_strjoin.o\
	ft_strlcat.o\
	ft_strlen.o\
	ft_strmap.o\
	ft_strmapi.o\
	ft_strncat.o\
	ft_strncmp.o\
	ft_strncpy.o\
	ft_strnequ.o\
	ft_strnew.o\
	ft_strnstr.o\
	ft_putchar.o\
	ft_strrchr.o\
	ft_strsplit.o\
	ft_strstr.o\
	ft_strsub.o\
	ft_strtrim.o\
	ft_uintlen.o\
	get_next_line.o

OBJ:=$(addprefix ./obj/, $(ITEM))

VPATH:=src:inc

HEADER:=ft_string.h get_next_line.h

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

