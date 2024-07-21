//
// Created by nikita on 7/15/24.
//

#include "Window.hpp"

namespace ncurses_oop
{

	Window::Window(uint32_t width, uint32_t height, uint32_t x, uint32_t y,
				   WINDOW *window)
		: _width(width), _height(height)
		, _x(x + width), _y(y + height), _window(window)
	{
		box(_window, 0, 0);
		wrefresh(_window);
	}

	Window::Window(dimensions b, coordinates a, WINDOW *window)
		: Window(b.first, b.second, a.first, a.second, window) {}

	Window::~Window()
	{
		delwin(_window);
	}

	[[nodiscard]] constexpr uint32_t Window::getWidth() const
	{
		return _width;
	}

	[[nodiscard]] constexpr uint32_t Window::getHeight() const
	{
		return _height;
	}

}