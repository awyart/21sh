####
# FT_MEM
####

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_LIB:=-L $(FT_MEM_DIR) -lftmem
FT_MEM_INC:=-I $(FT_MEM_DIR)/$(INC_D)

####
# FT_STRING
####

FT_STRING:=ft_string
FT_STRING_DIR:=$(LIB_D)/$(FT_STRING)
FT_STRING_LIB:=-L $(FT_STRING_DIR) -lftstring
FT_STRING_INC:=-I $(FT_STRING_DIR)/$(INC_D)

####
# FT_TERM
####

FT_TERM:=ft_term
FT_TERM_DIR:=$(LIB_D)/$(FT_TERM)
FT_TERM_LIB:=-L $(FT_TERM_DIR) -lftterm
FT_TERM_INC:=-I $(FT_TERM_DIR)/$(INC_D)

####
# FT_DLIST
####

FT_DLIST:=ft_dlist
FT_DLIST_DIR:=$(LIB_D)/$(FT_DLIST)
FT_DLIST_LIB:=-L $(FT_DLIST_DIR) -lftdlist
FT_DLIST_INC:=-I $(FT_DLIST_DIR)/$(INC_D)

####
# FT_INPUT_READER
####

FT_INPUT_READER:=ft_input_reader
FT_INPUT_READER_DIR:=$(LIB_D)/$(FT_INPUT_READER)
FT_INPUT_READER_LIB:=-L $(FT_INPUT_READER_DIR) -lftinput_reader
FT_INPUT_READER_INC:=-I $(FT_INPUT_READER_DIR)/$(INC_D)


####
# FT_PRINTF
####

FT_PRINTF:=ft_printf
FT_PRINTF_DIR:=$(LIB_D)/$(FT_PRINTF)
FT_PRINTF_LIB:=-L $(FT_PRINTF_DIR) -lftprintf
FT_PRINTF_INC:=-I $(FT_PRINTF_DIR)/$(INC_D)

####
# LIBFT
####

LIBFT:=libft
LIBFT_DIR:=$(LIB_D)/$(LIBFT)
LIBFT_LIB:=-L $(LIBFT_DIR) -lft
LIBFT_INC:=-I $(LIBFT_DIR)/$(INC_D)

####
# DATA VARS
####

INCLUDES+=\
		  $(FT_MEM_INC)\
		  $(FT_STRING_INC)\
		  $(FT_DLIST_INC)\
		  $(FT_INPUT_READER_INC)\
		  $(FT_TERM_INC) \
		  $(FT_PRINTF_INC)\
		  $(LIBFT_INC)
LIBRARIES:=\
		   $(FT_MEM_LIB)\
		   $(FT_STRING_LIB)\
		   $(FT_DLIST_LIB)\
		   $(FT_INPUT_READER_LIB)\
		   $(FT_TERM_LIB)\
		   $(FT_PRINTF_LIB) \
		   $(LIBFT_LIB) \
		   -lcurses
