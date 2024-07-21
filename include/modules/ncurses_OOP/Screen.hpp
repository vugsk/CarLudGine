
#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP

#include "Config.hpp"
#include "Output.hpp"

namespace ncurses_oop
{
	class IWindow;

	class Screen : public Output
	{
	public:
		~Screen();
		Screen(const Screen&) = delete;
		Screen(Screen&&) = delete;
		Screen& operator=(const Screen&) = delete;
		Screen& operator=(Screen&&) = delete;

		static Screen *init(size_X width = 0, size_Y height = 0);

		[[nodiscard]] std::unique_ptr<IWindow>
			createWindow(size_X x, size_Y y, size_X width, size_Y height);

		[[nodiscard]] int getWidth() const;
		[[nodiscard]] int getHeight() const;

	private:
		explicit Screen(size_X width = 0, size_Y height = 0);

		static Screen *ptrWindow;

		size_X _width;
		size_Y _height;
		WINDOW *_window;
	};

}
#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
