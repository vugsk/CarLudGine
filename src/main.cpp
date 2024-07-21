
#include <iostream>

#include "Window.hpp"
#include "Screen.hpp"


using ncurses_oop::Screen;
using ncurses_oop::IWindow;

int main()
{
	Screen* wt = Screen::init();
	wt->print(wt->getWidth(), wt->getHeight());

	getch();

	delete wt;

    return 0;
}