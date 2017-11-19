NAME:=libft.a

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
	ft_islower.o \
	ft_strncmp.o \
	ft_isnu.o \
	ft_strncpy.o \
	ft_isprint.o \
	ft_strncpy_ret.o \
	ft_isspace.o \
	ft_uitoa_str.o \
	ft_isupper.o \
	ft_ultoa.o \
	ft_itoa_base.o \
	ft_ultoa_base.o \
	ft_abs.o \
	ft_itoa_str.o \
	ft_atoi.o \
	ft_lltoa_str.o \
	ft_atoi_base.o \
	ft_ltoa_base.o \
	ft_bzero.o \
	ft_ltoa_str.o \
	ft_cap_itoa_base.o \
	ft_isalnum.o \
	ft_putchar_uni.o \
	ft_isalpha.o \
	ft_putstr_uni.o \
	ft_isascii.o \
	ft_strcmp.o \
	ft_isc.o \
	ft_strcpy.o \
	ft_isdigit.o \
	ft_strcpy_ret.o \
	ft_iseven.o \
	ft_strlen.o

OBJ:=$(addprefix ./obj/, $(ITEM))

VPATH:=src:inc

HEADER:= libftprintf.h

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

