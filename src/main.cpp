
#include <iostream>

#include "Window.hpp"
#include "Screen.hpp"


using ncurses_oop::Screen;
using ncurses_oop::IWindow;

int main()
{
	Screen* wt = Screen::init();
//	wt->print("% %", wt->getWidth(), wt->getHeight());
	wt->movePrint(10, 5, wt->getWidth(), wt->getHeight());

//	auto win = wt->createWindow(10, 5, 50, 10);
//	win->print("%d %d", win->getWidth(), win->getHeight());

	getch();

	delete wt;

    return 0;
}