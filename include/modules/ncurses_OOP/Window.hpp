//
// Created by nikita on 7/15/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP

#include "Config.hpp"
#include "InterfaceBasicBox.hpp"

namespace ncurses_oop
{
	class Window : public InterfaceBasicBox
	{
	public:
		Window(uint32_t width, uint32_t height, uint32_t x,
			   uint32_t y, WINDOW *window);
		Window(dimensions b, coordinates a, WINDOW *window);
		~Window() override;
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		[[nodiscard]] constexpr uint32_t getWidth() const final;
		[[nodiscard]] constexpr uint32_t getHeight() const final;

	private:
		const uint32_t _width;
		const uint32_t _height;
		const uint32_t _x;
		const uint32_t _y;

		WINDOW *_window;
	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP
