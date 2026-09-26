#pragma once

#include "Space.hpp"
#include "MaterialTranslation.hpp"
#include "Materials.hpp"

#include <iostream>

int physic(Space& space) {
	// Copying the current space matrix for physics calculations
	std::vector space_matrix{ space.get_space() };


	// Going through the whole matrix from bottom to top
	for (int32_t y = space.height - 1; y >= 0; y--) {
		for (int32_t x = space.width - 1; x >= 0; x--) {
			Vector2 position(x, y);
			int8_t current_material = space_matrix[y * space.width + x];

			// Skip the cell if it is empty
			if (space.is_empty(Vector2(x, y)) || 
					material_registry.at(static_cast<int8_t>(material_translator::wood))->physic_status == false)
				continue;

			// Checking if the current cell contains sand
			if (current_material ==
				static_cast<std::int8_t>(material_translator::sand)) {

				material_registry.at(
					static_cast<int8_t>(material_translator::sand))->behavior(space, position, Vector2(space.width, space.height));
			}
			// Checking if the current cell contains water
			else if (current_material ==
				static_cast<std::int8_t>(material_translator::water)) {

				material_registry.at(
					static_cast<int8_t>(material_translator::water))->behavior(space, position, Vector2(space.width, space.height));
			}
			// Checking if the current cell contains wood
			else if (current_material ==
				static_cast<std::int8_t>(material_translator::wood)) {

				material_registry.at(
					static_cast<int8_t>(material_translator::wood))->behavior(space, position, Vector2(space.width, space.height));
			}
		}
	}

	return 0;
}
