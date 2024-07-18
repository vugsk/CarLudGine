//
// Created by nikita on 7/15/24.
//

#include "Screen.hpp"

#include "Window.hpp"

namespace ncurses_oop
{
	Screen *Screen::ptrWindow = nullptr;

	Screen *Screen::init(size_X width, size_Y height)
	{
		return ptrWindow ?: new Screen(width, height);
	}

	void Screen::print(const char *format, ...) const
	{
		va_list args;
		va_start(args, format);
		printWindow<size_X, size_Y>(_window, format, args);
		va_end(args);
	}

	void Screen::mvprint(size_X x, size_Y y, const char *format, ...) const
	{
		va_list args;
		va_start(args, format);
		printWindow(_window, format, args, x, y);
		va_end(args);
	}

	[[nodiscard]] size_X Screen::getWidth() const
	{
		return _width;
	}

	[[nodiscard]] size_Y Screen::getHeight() const
	{
		return _height;
	}

	IWindow *Screen::createWindow(size_X x, size_Y y, size_X width, size_Y height)
	{
		return new Window(width, height, x, y,
						  newwin(height, width, y, x));
	}

	Screen::Screen(size_X width, size_Y height)
	{
		initscr();
		_window = stdscr;
		_width  = width ?: getmaxx(_window);
		_height = height ?: getmaxy(_window);
	}

	Screen::~Screen()
	{
		endwin();
	}

}