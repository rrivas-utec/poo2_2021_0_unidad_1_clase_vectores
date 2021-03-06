//
// Created by rudri on 2/3/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_SHAPE_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_SHAPE_H

#include "common_types.h"
#include "platform_types.h"

namespace utec {
    class shape_t {
    protected:
        position_t position{};
        dimension_t dimension{};
        color_t color{};
        velocity_t velocity{};
    public:
        shape_t(position_t p, dimension_t d, color_t c, velocity_t v):
            position{p}, dimension{d}, color{c}, velocity{v} {}
//        shape_t() = default;
//        shape_t(shape_t const& other) = default;
//        shape_t(shape_t&& other) = default;
//        shape_t& operator=(shape_t const& other) = default;
//        shape_t& operator=(shape_t&& other) = default;
//        ~shape_t() = default;
        virtual ~shape_t() = default;
        virtual void draw() = 0;
        virtual void move() = 0;
        friend void bounce_wall(shape_t* a);
        friend bool have_collided(shape_t* a, shape_t* b);
        friend void bounce(shape_t* a, shape_t* b);
    };

    class rectangle_t: public shape_t {
        using shape_t::shape_t; // Para heredar el constructor del padre
    public:
//        rectangle_t(position_t p, dimension_t d, color_t c, velocity_t v):
//            shape_t(p, d, c, v) {}
        void draw() override;
        void move() override;
    };

    class ellipse_t: public shape_t {
        using shape_t::shape_t;
    public:
        void draw() override;
        void move() override;
    };

    // Verifica la colision y realiza el rebote con las paredes
    void bounce_wall(shape_t* a);

    // Verifica la colision entre 2 figuras
    bool have_collided(shape_t* a, shape_t* b);

    // Realiza el rebote entre 2 figuras
    void bounce(shape_t* a, shape_t* b);
}

#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_SHAPE_H
