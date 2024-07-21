
#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP

#include "Config.hpp"
#include "Output.hpp"
#include "CreateBasicBox.hpp"
#include "InterfaceBasicBox.hpp"

namespace ncurses_oop
{

	class Screen
		: public Output, public CreateBasicBox<InterfaceBasicBox>
	{
	public:
		~Screen();
		Screen(const Screen&) noexcept = delete;
		Screen& operator=(const Screen&) noexcept = delete;
		Screen(Screen&& other) noexcept;
		Screen& operator=(Screen&& other) noexcept;

		static Screen&& init(uint32_t width = 0, uint32_t height = 0);

		[[nodiscard]] uint32_t getWidth() const;
		[[nodiscard]] uint32_t getHeight() const;

	private:
		explicit Screen(uint32_t width = 0, uint32_t height = 0);

		uint32_t _width;
		uint32_t _height;
		WINDOW *_window;
	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_SCREEN_HPP
