#pragma once
class view{
	public: 
		virtual ~view(){};
		static view* get(char const* type);
		virtual void draw() = 0;
		virtual void mainloop() = 0;
	private:
		static view* obj;
};