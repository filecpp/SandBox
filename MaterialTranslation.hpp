#pragma once

#include <cstdint>

enum class material_translator : std::int8_t {
	empty = -1,
	sand = 0,
	water = 1,
	wood = 2,
};
