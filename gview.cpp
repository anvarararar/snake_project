#include "gview.h"
#include <stdio.h>

gview::gview()
{
	printf("GUI\n");
}

void gview::draw()
{
	printf("Hello, it's gdraw");
}

void gview::mainloop()
{
	while(1)
	{
		draw();
	}
}