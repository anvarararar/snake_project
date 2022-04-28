#pragma once
#include "view.h"

class gview: public view{
	public:
		gview();
		virtual void draw();
		virtual void mainloop();
};