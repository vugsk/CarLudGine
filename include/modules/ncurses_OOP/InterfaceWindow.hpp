//
// Created by nikita on 7/15/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEWINDOW_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEWINDOW_HPP

#include "Config.hpp"

namespace ncurses_oop
{

	class IWindow
	{
	public:
		virtual void print(const char *format, ...) const = 0;
		virtual void mvprint(size_X x, size_Y y,
							 const char *format, ...) const = 0;
		[[nodiscard]] virtual IWindow *createWindow(size_X x, size_Y y,
													size_X width,
		                                            size_Y height) const = 0;

		[[nodiscard]] virtual size_X getWidth() const = 0;
		[[nodiscard]] virtual size_Y getHeight() const = 0;
		[[nodiscard]] virtual size_X getX() const = 0;
		[[nodiscard]] virtual size_Y getY() const = 0;


		virtual ~IWindow() = default;
	};

}
#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEWINDOW_HPP
