#ifndef AUTOCOMPLETE_H
# define AUTOCOMPLETE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>

# include "levenshtein.h"

void		history_init(t_hist *hstruct);
t_dlist		*history_handler(int event, t_dlist *input, t_hist *hstruct);

#endif
