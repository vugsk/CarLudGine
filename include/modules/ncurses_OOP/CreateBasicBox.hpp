//
// Created by nikita on 7/21/24.
//

#ifndef CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CREATEBASICBOX_HPP
#define CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CREATEBASICBOX_HPP

#include "Config.hpp"

namespace ncurses_oop
{
	template<typename I, typename C>
	class CreateBasicBox
	{
	public:
		CreateBasicBox(const CreateBasicBox&) = delete;
		CreateBasicBox(CreateBasicBox&&) = delete;
		CreateBasicBox& operator=(const CreateBasicBox&) = delete;
		CreateBasicBox& operator=(CreateBasicBox&&) = delete;
		explicit CreateBasicBox(uint32_t x, uint32_t y)
			: _x(x), _y(y) {}
		~CreateBasicBox() = default;

		[[nodiscard]] constexpr std::unique_ptr<I> create(dimensions a,
														  coordinates b)
		{
			return std::make_unique<C>(a, b,
					   newwin(convert<int>(a.second),
                              convert<int>(a.first),
                              convert<int>(convert_test(_y - b.second, _y)),
                              convert<int>(convert_test(_x - b.first, _x))));
		}

	protected:
		[[nodiscard]] constexpr uint32_t
			convert_test(uint32_t num, uint32_t bigger) const
		{
			return bigger == 0 && num > bigger ? ((num ^ maxInt) + 1) : num;
		}

	private:
		const uint32_t maxInt = 4294967295;

		const uint32_t _y;
		const uint32_t _x;

	};

}

#endif //CARLUDGINE_INCLUDE_MODULES_NCURSES_OOP_CREATEBASICBOX_HPP
