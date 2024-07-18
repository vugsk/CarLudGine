//
// Created by nikita on 7/18/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP

#include <ncurses.h>

namespace ncurses_oop
{
	template<typename T>
	concept isNumber = requires(T t) { t - t; };

	using size_X = int;
	using size_Y = int;

	template<isNumber T1, isNumber T2>
	void printWindow(WINDOW* window, const char* format, va_list args,
					 T1 x = 0, T2 y = 0)
	{
		wmove(window, y, x);
		vw_printw(window, format, args);
		wrefresh(window);
	}

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP
