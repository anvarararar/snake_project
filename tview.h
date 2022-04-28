#pragma once
#include "view.h"
class tview: public view{
	public:

		tview();
		~tview();
		virtual void draw();
		virtual void mainloop();
	private:
		void gotoxy(int x, int y);
		void putc(char c);
		void puts(const char* s);
		void setcolor(int color);
		void hline(char c, int x, int y, int length);
		void vline(char c, int x, int y, int high);
		void cleanscr();
};