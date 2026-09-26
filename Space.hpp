#pragma once

#include "Screen.hpp"
#include "MaterialTranslation.hpp"
#include "Vector2.hpp"

#include <iostream>
#include <cstdint>
#include <vector>

class Space final {
private:
    std::vector<std::int8_t> cells;

public:
    static constexpr int width = 720;
    static constexpr int height = 480;

    Space() {
        cells.resize(width * height);
    }

    void add(Vector2 position, material_translator material) {
        cells[position.y * width + position.x] =
            static_cast<std::int8_t>(material);
    }

    void move(Vector2 position, Vector2 target_position) {
        const auto source = position.y * width + position.x;
        const auto target = target_position.y * width + target_position.x;

        const auto material = cells[source];

        cells[target] = material;
        cells[source] = -1;
    }

    [[nodiscard]]
    const std::vector<std::int8_t>& get_space() const noexcept {
        return cells;
    }
};
