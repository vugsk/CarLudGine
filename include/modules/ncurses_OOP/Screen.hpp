
#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP

#include "Config.hpp"

namespace ncurses_oop
{
	class IWindow;

	class Screen
	{
	public:
		~Screen();

		static Screen *init(size_X width = 0, size_Y height = 0);

		void print(const char *format, ...) const;
		void mvprint(size_X x, size_Y y, const char *format, ...) const;

		[[nodiscard]] IWindow *createWindow(size_X x, size_Y y, size_X width,
									  size_Y height);

		[[nodiscard]] size_X getWidth() const;
		[[nodiscard]] size_Y getHeight() const;

	private:
		explicit Screen(size_X width = 0, size_Y height = 0);

		static Screen *ptrWindow;

		size_X _width;
		size_Y _height;
		WINDOW *_window;
	};

}
#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
