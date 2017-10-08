#ifndef DEFNE_H
# define DEFNE_H

/*Color pattern*/

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

/*Unicode values*/

# define EMJ_ARRW 0x27A1 /*arrow*/
# define UPDOWN 0x1f643 /*amo*/

/*numer of command and the len of their name*/

# define PRC_LEN 9
# define MAX_CMD_NAME 10

/*number of escape sentences*/

# define SCHAR_NB 11

/*debug MACROS*/

# define STR(x)		ft_printf(#x " = |%s|\n", x)
# define NBR(x)		ft_printf(#x " = |%d|\n", x)
# define CHR(x)		ft_printf(#x " = |%c|\n", x)
# define TAB(x)		\
					while (*x)\
					{\
						ft_printf("|%s|\n", *x);\
						x++;\
					}
# define ICI		ft_printf("ICI\n");
# define LA			ft_printf("LA\n");
# define EX			exit(1);

#endif
