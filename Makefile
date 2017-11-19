NAME:=42sh
CC:=gcc

RM:=/bin/rm -f
MKDIR:=mkdir -p

CFLAGS:=-Wall -Wextra -Werror

INC_D:=inc
SCR_D:=src
LIB_D:=lib
OBJ_D:=obj

INC:=-I $(INC_D)
INCLUDES:=$(INC)
ITEM:=\
	main.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

include libs.mk

vpath %.c src
vpath %.h inc

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(FT_MEM_DIR)
	@$(MAKE) -C $(FT_STRING_DIR)
	@$(MAKE) -C $(FT_TERM_DIR)
	@$(MAKE) -C $(FT_DLIST_DIR)
	@$(MAKE) -C $(FT_INPUT_READER_DIR)
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)

$(OBJ_D)/%.o: %.c $(HEADER)
	@$(MKDIR) $(OBJ_D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	@$(MAKE) -C $(FT_MEM_DIR) clean
	@$(MAKE) -C $(FT_STRING_DIR) clean
	@$(MAKE) -C $(FT_TERM_DIR) clean
	@$(MAKE) -C $(FT_DLIST_DIR) clean
	@$(MAKE) -C $(FT_INPUT_READER_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJ_D)

fclean: clean
	@$(MAKE) -C $(FT_MEM_DIR) fclean
	@$(MAKE) -C $(FT_STRING_DIR) fclean
	@$(MAKE) -C $(FT_TERM_DIR) fclean
	@$(MAKE) -C $(FT_DLIST_DIR) fclean
	@$(MAKE) -C $(FT_INPUT_READER_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
