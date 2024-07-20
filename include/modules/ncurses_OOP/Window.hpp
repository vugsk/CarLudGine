//
// Created by nikita on 7/15/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP

#include "InterfaceWindow.hpp"

namespace ncurses_oop
{
	class Window : public IWindow
	{
	public:
		Window(size_X width, size_Y height, size_X x, size_Y y, WINDOW *window);
		~Window() override;
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		[[nodiscard]] std::unique_ptr<IWindow> createWindow(size_X x, size_Y y,
															size_X width,
															size_Y height) const final;
		void print(const char *format, ...) const final;
		void mvprint(size_X x, size_Y y, const char *format, ...) const final;

		[[nodiscard]] size_X getWidth() const final;
		[[nodiscard]] size_Y getHeight() const final;
		[[nodiscard]] size_X getX() const final;
		[[nodiscard]] size_Y getY() const final;
	private:
		const size_X _width;
		const size_Y _height;

		const size_X _x;
		const size_Y _y;

		WINDOW *_window;
	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_WINDOW_HPP
