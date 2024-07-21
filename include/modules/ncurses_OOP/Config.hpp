//
// Created by nikita on 7/18/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP

#include <functional>
#include <ncurses.h>
#include <memory>

namespace ncurses_oop
{

	using coordinates = std::pair<uint32_t, uint32_t>;
	using dimensions = std::pair<uint32_t, uint32_t>;

	template<typename T>
	concept IsNumber = std::integral<T> || std::floating_point<T>;


	template<typename To, typename From>
	constexpr To convert(const From& from)
	{
		return static_cast<To>(from);
	}

	template<typename To, typename From>
	constexpr To convert(From&& from)
	{
		return static_cast<To>(from);
	}

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CONFIG_HPP
