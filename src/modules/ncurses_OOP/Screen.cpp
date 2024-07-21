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
		return ptrWindow = ptrWindow ?: new Screen(width, height);
	}

	[[nodiscard]] int Screen::getWidth() const
	{
		return _width;
	}

	[[nodiscard]] int Screen::getHeight() const
	{
		return _height;
	}

	std::unique_ptr<IWindow> Screen::createWindow(size_X x, size_Y y, size_X width,
										  size_Y height)
	{
		return std::make_unique<Window>(width, height, x, y,
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