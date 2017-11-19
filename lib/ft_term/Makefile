NAME:=libftterm.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

OBJ_D:=obj
LIB_D:=..
INC_D:=inc
SRC_D:=src

INC:=-I $(INC_D)

###
# FT_MEM
# ###

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_INC:=-I $(FT_MEM_DIR)/$(INC_D)

INCLUDES:=\
	$(INC)\
	$(FT_MEM_INC)

VPATH:=src:inc
HEADER:=ft_dlist.h

ITEM:=\
	ft_terms.o\
	ft_terms_get.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

RM=/bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

${OBJ_D}/%.o: %.c #$(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(RM) -r $(OBJ_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all
