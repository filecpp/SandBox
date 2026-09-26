#pragma once

#include "Screen.hpp"
#include "MaterialTranslation.hpp"
#include "Vector2.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

// Stores all cells of the space
class Space final {
private:
    std::vector<std::int8_t> cells;

public:
    static constexpr int width = 720;
    static constexpr int height = 480;

    Space() {
        cells.resize(width * height);
    }

    void clear() noexcept {
        for (auto& cell : cells)
            cell = -1;
    }

    // Checks if the cell is empty
    bool is_empty(Vector2 position) const noexcept {
        return cells[position.y * width + position.x] ==
            static_cast<std::int8_t>(material_translator::empty);
    }

    // Adds a material to the specified cell
    void add(Vector2 position, material_translator material) {
        cells[position.y * width + position.x] =
            static_cast<std::int8_t>(material);
    }

    // Moves a material from one cell to another
    void move(Vector2 position, Vector2 target_position) {
        const auto source = position.y * width + position.x;
        const auto target = target_position.y * width + target_position.x;

        const auto material = cells[source];

        cells[target] = material;
        cells[source] = -1;
    }

    // Checks if the position is within the space
    [[nodiscard]]
    bool in_bounds(Vector2 p) const noexcept {
        return p.x >= 0 &&
            p.x < width &&
            p.y >= 0 &&
            p.y < height;
    }

    // Returns all cells of the space
    [[nodiscard]]
    const std::vector<std::int8_t>& get_space() const noexcept {
        return cells;
    }
};
