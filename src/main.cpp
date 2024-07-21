
#include "Screen.hpp"

using ncurses_oop::Screen;
using ncurses_oop::windowPtr;

int main()
{

	Screen wt(Screen::init());
	wt.print(wt.getWidth(), wt.getHeight());

	windowPtr io = wt.create({50, 5}, {5, 5});

	getch();

    return 0;
}