#include "Error.hpp"
#include "Space.hpp"
#include "Client.hpp"
#include "Physic.hpp"

#include "MaterialTranslation.hpp"

#include <iostream>
#include <thread>
#include <chrono>
#include <string>

int main() {
	Space space;
	space.clear();

	space.add(Vector2(2, 2), material_translator::sand);
	std::vector space_matrix = space.get_space();

	std::cout << static_cast<const int>(space_matrix[2 * space.width + 2]) << " material.\n";
	std::cout << static_cast<const int>(space_matrix[3 * space.width + 2]) << " material.\n";

	physic(space);
	space_matrix = space.get_space();

	std::cout << static_cast<const int>(space_matrix[2 * space.width + 2]) << " material.\n";
	std::cout << static_cast<const int>(space_matrix[3 * space.width + 2]) << " material.\n";

	return 0;
} 
