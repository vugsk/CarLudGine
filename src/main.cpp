
#include <iostream>
#include <memory>

#include "Window.hpp"
#include "Screen.hpp"


using ncurses_oop::Screen;
using ncurses_oop::IWindow;

int main()
{
	std::unique_ptr<IWindow> wt = Screen::init();
	wt->print("%d %d", wt->getWidth(), wt->getHeight());

	auto win = wt->createWindow(10, 5, 50, 10);
	win->print("%d %d", win->getWidth(), win->getHeight());

	getch();

    return 0;
}