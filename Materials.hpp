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

class Material {
private:
	// String variables with the name of the material and its description
	std::string name{"Unknown"};
	std::string description{"No description available"};

	// Boolean variable indicating whether the material has physical properties or not
	int8_t physic_status{false};
public:
	// Basic functions of the constructor and how it should respond to different events
	Material() noexcept						  { 
		std::cerr << "Material default constructor called\n"; }
	virtual ~Material() noexcept				  {
		std::cerr << "Material destructor called\n";		  }

	// Function if 2 argumets called in [name, description]
	Material(const std::string name, const std::string description) : 
		name(std::move(name)), description(std::move(description)) { }

	// [Setters, getters] - thanks to which we [get, set] information
	virtual void set_name(const std::string& name) noexcept { this->name = std::move(name); }
	virtual void set_description(const std::string& description) noexcept { this->description = std::move(description); }

	[[nodiscard]] virtual const std::string& get_name() const noexcept { return name; }
	[[nodiscard]] virtual const std::string& get_description() const noexcept { return description; }
	
	// Behavior - what will trigger all sorts of effects of this material
	virtual void behavior(Space& space) noexcept { std::cerr << "Material behavior called\n"; }
};

class Sand : public Material {
public:
	Sand() {
		set_name("Sand");
		set_description("A pile of sand");
	}

	void behavior(Space& space) noexcept override {
		space.move(Vector2(2, 2), Vector2(3, 3));
	}
};

class Water : public Material {
public:
	Water() {
		set_name("Water");
		set_description("Liquid water");
	}

	void behavior(Space& space) noexcept override {
		std::cout << "Water flows\n";
		space.move(Vector2(2, 2), Vector2(3, 3));
	}
};

class Wood : public Material {
public:
	Wood() {
		set_name("Wood");
		set_description("A piece of wood");
	}

	void behavior(Space& space) noexcept override {
		std::cout << "Wood burns\n";
		space.move(Vector2(2, 2), Vector2(3, 3));
	}
};

inline std::unordered_map<std::string, std::unique_ptr<Material>> material_registry {
	{ "sand", std::make_unique<Sand>() },
	{ "water", std::make_unique<Water>() },
	{ "wood", std::make_unique<Wood>() },
};

