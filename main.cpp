//#include <iostream>
//#include <SFML/Graphics.hpp>

#include "render.h"
#include "shape.h"
#include "my_vector.h"
#include <thread>
#include <chrono>

using namespace utec;
using namespace std::chrono_literals;

int main()
{
    auto render = utec::render_t::get_instance(
            {600, 400}, "Unidad 1");
    auto& p_render = render->get_platform_render();

    utec::vector vec1;
    vec1.push_back(new rectangle_t({100.0f, 100.0f}, {10.0f, 10.0f},
                                   color_t::Red, {2.0f, 3.0f}));
    vec1.push_back(new ellipse_t({200.0f, 200.0f}, {10.0f, 10.0f},
                                   color_t::Yellow, {3.0f, 2.0f}));

    while (p_render.isOpen())
    {
        sf::Event event{};
        while (p_render.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                p_render.close();
        }
        // Evaluacion de colision
        for (size_t i = 0; i < vec1.size(); ++i) {
            // rebote con las paredes
            bounce_wall(vec1[i]);
            for (size_t j = i + 1; j < vec1.size(); ++j) {
                if (have_collided(vec1[i], vec1[j]))  // Sugerencia implementar una interseccion de figuras
                    // rebote entre figuras
                    bounce(vec1[i], vec1[j]);   // Intercambio de velocidad
            }
        }

        p_render.clear(color_t::Blue);
        for (size_t i = 0; i < vec1.size(); ++i) {
            vec1[i]->draw();
            vec1[i]->move();
        }
        p_render.display();
        std::this_thread::sleep_for(10ms);
    }

    return 0;
}