#include "tview.h"
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>
#include <poll.h>
#define TIMESLEEP 500000

struct termios old;
bool final = false;

void onsig(int n)
{
	final = true;
	fprintf(stderr, "EXIT");
}

tview::tview()
{
	struct termios s;
	tcgetattr(0, &s);
	old = s;
	cfmakeraw(&s);
	s.c_lflag |= ISIG;
	tcsetattr(0, TCSANOW, &s);
	signal(SIGINT, onsig);
}

tview::~tview()
{
	tcsetattr(0, TCSANOW, &old);
	cleanscr();
	printf("GOOD BYE!\n");
}

void tview::draw()
{
	cleanscr();
	setcolor(1);
	hline('#', 1, 1, 90);
	hline('#', 1, 24, 90);
	vline('#', 1, 2, 23);
	vline('#', 91, 1, 24);
	gotoxy(43, 1);
	setcolor(7);
	puts("SNAKE");
	gotoxy(4, 23);
	puts("CURRENT POINTS:");

}

void tview::mainloop()
{
	struct pollfd fd = {0, POLLIN};
	while(!final)
	{
		draw();
		int n = poll(&fd, 1, 500);
		if(n == 1)
		{
			char c;
			if(read(0, &c, 1) == 1)
			{
				if(c == 'q')
				{
					final = true;
				}
			}
		}
	}
}

void tview::cleanscr()
{
	printf("\e[H");
	fflush(stdout);
	printf("\e[J");
	fflush(stdout);
}

void tview::gotoxy(int x, int y)
{
	printf("\e[%d;%dH", y, x);
	fflush(stdout);
}

void tview::putc(char c)
{
	printf("%c", c);
	fflush(stdout);
}

void tview::puts(const char* s)
{
	printf("%s", s);
	fflush(stdout);
}

void tview::setcolor(int color)
{
	printf("\e[%dm", color + 30);
	fflush(stdout);
}

void tview::hline(char c, int x, int y, int len)
{
	for (int i = 0; i < len; ++i)
	{
		gotoxy(x, y);
		putc(c);
		x++;
	}
}

void tview::vline(char c, int x, int y, int h)
{
	for (int i = 0; i < h; ++i)
	{
		gotoxy(x, y);
		putc(c);
		y++;
	}
}