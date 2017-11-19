NAME:=libftdlist.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

OBJ_D:=obj
LIB_D:=..

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_INC:=$(FT_MEM_DIR)/inc

INC_D:=\
	-I inc\
	-I $(FT_MEM_INC)
VPATH:=src:inc
HEADER:=ft_dlist.h

ITEM:=\
ft_dlist_create.o\
ft_dlist_clear.o\
ft_dlist_findchar.o\
ft_dlist_from.o\
ft_dlist_free.o\
ft_dlist_insert.o\
ft_dlist_last.o\
ft_dlist_len.o\
ft_dlist_replace.o\
ft_dlist_swap.o\
ft_dlist_to_str.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

RM=/bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

${OBJ_D}/%.o: %.c #$(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_D)

clean:
	$(RM) -r $(OBJ_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all
