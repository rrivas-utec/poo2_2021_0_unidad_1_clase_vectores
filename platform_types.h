//
// Created by rudri on 2/3/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_PLATFORM_TYPES_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_PLATFORM_TYPES_H

#include <SFML/Graphics.hpp>
#include "common_types.h"

namespace utec {
    using color_t = sf::Color;
    using platform_render_t = sf::RenderWindow;
    auto get_render_size = [](const bound_t& bound) {
            return sf::VideoMode(bound.lim_x, bound.lim_y);
    };
}

#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_PLATFORM_TYPES_H
