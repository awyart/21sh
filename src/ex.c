#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <term.h>
#include <curses.h>

int main(void)
{
    int a = 0;
    int i = 0;
	int rows, col;
	char buf[1024];
	bzero(buf, 1024);
	struct termios term;

	int fd = open("/dev/tty", O_WRONLY);
	tgetent(NULL, getenv("TERM"));
	tcgetattr(fd, &term);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, TCSADRAIN, &term);

    write(fd, "\033[6n", 4); // string asking for the cursor position
	write(1, "WOLOLO!   ", 10);
	int pos = 0;
	while (1)
	{
		if (read(1, buf + pos, 1) == 0)
			break ;
		if (buf[pos] == 4)
		{
			buf[pos] = 0;
			break ;
		}
		pos++;
	}

	int fd2 = open("report.log", O_WRONLY | O_CREAT, 0644);
	write(fd2, buf, strlen(buf));
    while (buf[i])
    {
        if (buf[i] >= 48 && buf[i] <= 57)
        {
            if (a == 0)
                rows = atoi((&buf[i])) - 1;
            else
                col = atoi((&buf[i])) - 1;
            a++;
        }
        i++;
    }
	printf("col: %d, row: %d\n", col, rows);
}
