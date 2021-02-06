//
// Created by rudri on 2/5/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_RENDER_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_RENDER_H

#include "common_types.h"
#include "platform_types.h"

namespace utec {
    // Utilizando el patron singleton
    class render_t {
        // Atributos privados
        platform_render_t platform_render;
        inline static render_t* instance = nullptr;

        // Metodos privados
        render_t (const bound_t &bound, const std::string &title);
    public:
        // Destructor
        ~render_t () = default;
        // Metodos
        static render_t* get_instance(const bound_t &bound = {600, 400},
                                      const std::string &title = "Title");
        static void draw_rectangle(position_t p, dimension_t d, color_t c);
        static void draw_ellipse(position_t p, dimension_t d, color_t c);
        static bound_t get_limit();
        platform_render_t& get_platform_render();
    };
}


#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_RENDER_H
