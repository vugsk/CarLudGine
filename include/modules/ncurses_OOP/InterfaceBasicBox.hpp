//
// Created by nikita on 7/21/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEBASICBOX_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEBASICBOX_HPP

namespace ncurses_oop
{

	class InterfaceBasicBox
	{
	public:
		virtual ~InterfaceBasicBox() = default;

		[[nodiscard]] virtual constexpr uint32_t getWidth() const = 0;
		[[nodiscard]] virtual constexpr uint32_t getHeight() const = 0;
	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_INTERFACEBASICBOX_HPP
