
#include <iostream>

#include "Window.hpp"
#include "Screen.hpp"


using ncurses_oop::Screen;
using ncurses_oop::IWindow;

int main()
{
	Screen* wt = Screen::init();
	wt->print("%d %d", wt->getWidth(), wt->getHeight());

	IWindow* win = wt->createWindow(10, 5, 50, 10);
	win->print("%d %d", win->getWidth(), win->getHeight());

	getch();

	delete win;
	delete wt;

    return 0;
}