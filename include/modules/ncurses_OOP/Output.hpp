//
// Created by nikita on 7/21/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_OUTPUT_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_OUTPUT_HPP

#include "Config.hpp"

namespace ncurses_oop
{

	class Output
	{
	public:
		Output(const Output&) = delete;
		Output(Output&&) = delete;
		Output& operator=(const Output&) = delete;
		Output& operator=(Output&&) = delete;
		explicit Output(WINDOW*& win) : _window(win) {}
		~Output()
		{
			delwin(_window);
		}

		template<typename T> requires std::integral<T> || std::floating_point<T>
		constexpr void addString(T value) const
		{
			waddstr(_window, std::to_string(value).c_str());
		}

		constexpr void addString(const std::string& value) const
		{
			waddstr(_window, value.c_str());
		}

		template<typename T>
		constexpr void print(T format)
		{
			addString(format);
		}

		template<typename T, typename ...Args>
		constexpr void print(const T& val, Args... args)
		{
			addString(val);
			waddch(_window, ' ');
			print(args...);
			wrefresh(_window);
		}

		template<typename ...Args>
		constexpr void movePrint(const uint32_t x, const uint32_t y,
								 Args...args)
		{
			wmove(_window, static_cast<int>(y), static_cast<int>(x));
			print(args...);
		}

	private:
		WINDOW*& _window;

	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_OUTPUT_HPP
