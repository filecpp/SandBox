#pragma once

#include "Screen.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Space final {
private:
	std::vector<int8_t> space;
public:
	Space() noexcept {
		space.resize(Width * Height);
		std::cout << "Space constructor was created\n";
	}
	~Space() noexcept {
		std::cout << "Space constructor was removed\n";
	}

	// We use `move` as a way to carry material from one position to another
	void move(
				const int x,
				const int y,
				const int target_x,
				const int target_y) 
	{
		// Saving the index of the material that's at coordinates [x, y]
		int8_t last_material = space[y * (Width - 1) + x];
		
		// Were changing the space with the parameters we set
		space[target_y * (Height - 1) + target_x] = last_material;
		space[y * (Height - 1) + x] = -1;
	}
	
	// return the array space
	[[nodiscard]]
	const std::vector<int8_t>& space() const {
		return space;
	}
};
