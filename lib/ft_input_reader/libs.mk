###
# FT_MEM
###

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_INC:=-I $(FT_MEM_DIR)/$(INC_D)

###
# FT_DLIST
###

FT_DLIST:=ft_dlist
FT_DLIST_DIR:=$(LIB_D)/$(FT_DLIST)
FT_DLIST_INC:=-I $(FT_DLIST_DIR)/$(INC_D)

###
# FT_TERM
###

FT_TERM:=ft_term
FT_TERM_DIR:=$(LIB_D)/$(FT_TERM)
FT_TERM_INC:=-I $(FT_TERM_DIR)/$(INC_D)

INCLUDES+=\
		  $(FT_MEM_INC)\
		  $(FT_DLIST_INC)\
		  $(FT_TERM_INC)
