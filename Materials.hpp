#pragma once

#include "Error.hpp"

#include <iostream>
#include <string>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <stdexcept>

class Material {
private:
	// String variables with the name of the material and its description
	std::string name{"Unknown"};
	std::string description{"No description available"};

	// Boolean variable indicating whether the material has physical properties or not
	int8_t physic_status{false};
public:
	// Basic functions of the constructor and how it should respond to different events
	[[noreturn]] Material() noexcept		
		{ std::cerr << "Material default constructor called\n"; }
	[[noreturn]] virtual ~Material() noexcept 
		{ std::cerr << "Material destructor called\n"; }

	// [Setters, getters] - thanks to which we [get, set] information
	virtual void set_name(const std::string& name) noexcept { this->name = std::move(name); }
	virtual void set_description(const std::string& description) noexcept { this->description = std::move(description); }

	[[nodiscard]] virtual const std::string& get_name() const noexcept { return name; }
	[[nodiscard]] virtual const std::string& get_description() const noexcept { return description; }
	
	// Behavior - what will trigger all sorts of effects of this material
	virtual void behavior() noexcept { std::cerr << "Material behavior called\n"; }
};

/* 
 Sand - is the basic building block of the game
 and its behavior doesn't carry any surprising
 traits it just slides over other objects
 forming its figurative pyramid shape
*/
class Sand : public Material {
public:
	Sand() {
		set_name("Sand");
		set_description("A pile of sand");
	}

	void behavior() noexcept override {
		std::cout << "Sand falls down\n";
	}
};

/*
 Water - is the second basic element of the game
 it smoothly spreads out under the surface above
 which it is located
*/
class Water : public Material {
public:
	Water() {
		set_name("Water");
		set_description("Liquid water");
	}

	void behavior() noexcept override {
		std::cout << "Water flows\n";
	}
};

/*
 Wood is a material that burns and has no physical properties
*/
class Wood : public Material {
public:
	Wood() {
		set_name("Wood");
		set_description("A piece of wood");
	}

	void behavior() noexcept override {
		std::cout << "Wood burns\n";
	}
};

enum material_translator {
	sand = 0,
	water = 1,
	wood = 2,
};

inline std::unordered_map<std::string, std::unique_ptr<Material>> material_registry {
	{ "sand", std::make_unique<Sand>() },
	{ "water", std::make_unique<Water>() },
	{ "wood", std::make_unique<Wood>() },
};

