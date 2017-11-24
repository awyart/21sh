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
		   $(FT_PRINTF_INC)\
		  $(LIBFT_INC)
LIBRARIES:=\
		   $(FT_PRINTF_LIB) \
		   $(LIBFT_LIB) \
		   -lcurses
