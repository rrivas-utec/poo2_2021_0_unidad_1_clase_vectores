//
// Created by rudri on 2/3/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_COMMON_TYPES_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_COMMON_TYPES_H

namespace utec {
//    typedef float length_t;
//    typedef float speed_t;
    using length_t = float;
    using speed_t = float;
    using limit_t = size_t;

    struct position_t {
        length_t x;
        length_t y;
    };

    struct dimension_t {
        length_t width;
        length_t height;
    };

    struct velocity_t {
        speed_t vx;
        speed_t vy;
    };

    struct bound_t {
        limit_t lim_x;
        limit_t lim_y;
    };
}

#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_COMMON_TYPES_H
