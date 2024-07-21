
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
		Screen(const Screen&) = delete;
		Screen(Screen&&) = delete;
		Screen& operator=(const Screen&) = delete;
		Screen& operator=(Screen&&) = delete;

		static Screen *init(size_X width = 0, size_Y height = 0);

		template<typename T>
		void print(T format)
		{
			addString(format);
		}

		template<typename T> requires std::integral<T> || std::floating_point<T>
		void addString(T value)
		{
			waddstr(_window, std::to_string(value).c_str());
		}

		void addString(const std::string& value)
		{
			waddstr(_window, value.c_str());
		}

		template<typename T, typename ...Args>
	    void print(T val, Args... args)
		{
			addString(val);
			waddch(_window, ' ');
			print(args...);
		}

		template<typename T, typename ...Args>
		void movePrint(uint32_t x, uint32_t y, T val, Args... args)
		{
			wmove(_window, static_cast<int>(y), static_cast<int>(x));
			addString(val);
			waddch(_window, ' ');
			print(args...);
		}

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
