//
// Created by nikita on 7/15/24.
//

#include "Screen.hpp"

namespace ncurses_oop
{
	Screen&& Screen::init(uint32_t width, uint32_t height)
	{
		static Screen ptr(width, height);
		return std::move(ptr);
	}

	[[nodiscard]] uint32_t Screen::getWidth() const
	{
		return _width;
	}

	[[nodiscard]] uint32_t Screen::getHeight() const
	{
		return _height;
	}

	Screen::Screen(Screen&& other) noexcept
		: _width(0), _height(0), _window(nullptr)
		, Output(_window), CreateBasicBox<InterfaceBasicBox, Window>(0, 0)
    {
        _width = other._width;
	    _height = other._height;
	    _window = other._window;

	    other._width = 0;
	    other._height = 0;
	    other._window = nullptr;
    }

	Screen& Screen::operator=(Screen&& other) noexcept
	{
		if (this != &other)
		{
			_width = other._width;
			_height = other._height;
			_window = other._window;

			other._width = 0;
			other._height = 0;
			other._window = nullptr;
		}

		return *this;
	}

	Screen::Screen(uint32_t width, uint32_t height)
		: Output(stdscr)
		, CreateBasicBox<InterfaceBasicBox, Window>(width, height)
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