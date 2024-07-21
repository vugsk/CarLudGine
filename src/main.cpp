
#include "Window.hpp"
#include "Screen.hpp"

using ncurses_oop::Screen;
using ncurses_oop::Window;
using ncurses_oop::InterfaceBasicBox;
using ncurses_oop::Output;

int main()
{

	Screen wt(Screen::init());
	wt.print(wt.getWidth(), wt.getHeight());

	auto io = wt.create({50, 5}, {5, 5});

	getch();

    return 0;
}