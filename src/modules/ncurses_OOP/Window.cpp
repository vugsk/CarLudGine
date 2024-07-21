//
// Created by nikita on 7/15/24.
//

#include "Window.hpp"

namespace ncurses_oop
{

	Window::Window(size_X width, size_Y height, size_X x, size_Y y,
				   WINDOW *window)
		: _width(width), _height(height), _x(x + width)
		, _y(y + height), _window(window)
		, Output(window)
	{
		box(_window, 0, 0);
		wrefresh(_window);
	}

	Window::~Window()
	{
		delwin(_window);
	}

//	[[nodiscard]] std::unique_ptr<IWindow>
//	    Window::createWindow(size_X x, size_Y y, size_X width,
//							 size_Y height) const
//	{
//		return std::make_unique<Window>(width, height, x, y,
//										newwin(height, width,
//											          _y - y, _x - x));
//	}

	[[nodiscard]] size_X Window::getWidth() const
	{
		return _width;
	}

	[[nodiscard]] size_Y Window::getHeight() const
	{
		return _height;
	}

	[[nodiscard]] size_X Window::getX() const
	{
		return _x;
	}

	[[nodiscard]] size_Y Window::getY() const
	{
		return _y;
	}

}