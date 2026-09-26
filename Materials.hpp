#pragma once

#include "Error.hpp"
#include "Space.hpp"
#include "Vector2.hpp"

#include <iostream>
#include <string>
#include <cstdint>
#include <memory>
#include <utility>
#include <unordered_map>

// Base class for all materials used in the simulation
class Material {
private:
	// String variables with the name of the material and its description
	std::string name{ "Unknown" };
	std::string description{ "No description available" };

	// Boolean variable indicating whether the material has physical properties or not
	int8_t physic_status{ false };
public:
	// Basic functions of the constructor and how it should respond to different events
	Material() noexcept {
		std::cerr << "Material default constructor called\n";
	}
	virtual ~Material() noexcept {
		std::cerr << "Material destructor called\n";
	}

	// Function if 2 argumets called in [name, description]
	Material(const std::string name, const std::string description) :
		name(std::move(name)), description(std::move(description)) {
	}

	// [Setters, getters] - thanks to which we [get, set] information
	virtual void set_name(const std::string& name) noexcept { this->name = std::move(name); }
	virtual void set_description(const std::string& description) noexcept { this->description = std::move(description); }

	// Getting the name of the material
	[[nodiscard]] virtual const std::string& get_name() const noexcept { return name; }

	// Getting the description of the material
	[[nodiscard]] virtual const std::string& get_description() const noexcept { return description; }

	// Behavior - what will trigger all sorts of effects of this material
	virtual void behavior(Space& space, Vector2 position, Vector2 matrix_size) noexcept { std::cerr << "Material behavior called\n"; }
};

// Sand material and its own physical behavior
class Sand : public Material {
public:
	Sand() {
		// Setting the name and description of the material
		set_name("Sand");
		set_description("A pile of sand");
	}

	// Function responsible for the physical behavior of sand
	void behavior(Space& space, Vector2 position, Vector2 matrix_size) noexcept override {
		// Checking if the current cell contains sand
		if (space.get_space()[position.y * matrix_size.x + position.x] !=
			static_cast<int8_t>(material_translator::sand)) {

			std::cout << "Sand behavior\n";

			return;
		}
	}
};

// Water material and its own physical behavior
class Water : public Material {
public:
	Water() {
		// Setting the name and description of the material
		set_name("Water");
		set_description("Liquid water");
	}

	// Function responsible for the physical behavior of water
	void behavior(Space& space, Vector2 position, Vector2 matrix_size) noexcept override {
		// Checking if the current cell contains sand
		if (space.get_space()[position.y * matrix_size.x + position.x] !=
			static_cast<int8_t>(material_translator::sand)) {

			std::cout << "Water behavior\n";

			return;
		}
	}
};

// Wood material and its own physical behavior
class Wood : public Material {
public:
	Wood() {
		// Setting the name and description of the material
		set_name("Wood");
		set_description("A piece of wood");
	}

	// Function responsible for the physical behavior of wood
	void behavior(Space& space, Vector2 position, Vector2 matrix_size) noexcept override {
		// Checking if the current cell contains sand
		if (space.get_space()[position.y * matrix_size.x + position.x] !=
			static_cast<int8_t>(material_translator::sand)) {

			std::cout << "Wood behavior\n";

			return;
		}
	}
};

// Registry containing all available materials
inline std::unordered_map<int8_t, std::unique_ptr<Material>> material_registry{
	{ static_cast<int8_t>(material_translator::sand), std::make_unique<Sand>() },
	{ static_cast<int8_t>(material_translator::water), std::make_unique<Water>() },
	{ static_cast<int8_t>(material_translator::wood), std::make_unique<Wood>() },
};
