#pragma once

#include <cstdint>

enum class material_translator : std::int8_t {
	empty = int8_t{ -1 },
	sand = int8_t{ 0 },
	water = int8_t{ 1 },
	wood = int8_t{ 2 },
};
