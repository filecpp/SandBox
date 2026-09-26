#pragma once

#include <cstdint>

enum class material_translator : std::int8_t {
	empty = std::int8_t{ -1 },
	sand = std::int8_t{ 0 },
	water = std::int8_t{ 1 },
	wood = std::int8_t{ 2 },
};
