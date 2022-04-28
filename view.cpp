#include "view.h"
#include "tview.h"
#include "gview.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

view* view::obj = NULL;
view* view::get(const char* type)
{
	if(!obj)
	{
		if (!strcmp(type, "text"))
		{
			obj = new tview;
		}
		else if(!strcmp(type, "gui")) 
		{
			obj = new gview;
		}
		else
		{
			printf("No such view\n");
		}
	}
	return obj;
}