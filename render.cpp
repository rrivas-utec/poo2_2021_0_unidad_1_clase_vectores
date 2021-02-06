//
// Created by rudri on 2/5/2021.
//

#include "render.h"

utec::render_t::render_t(const utec::bound_t &bound, const std::string &title):
    platform_render {get_render_size(bound), title} {
}

utec::render_t *utec::render_t::get_instance(const utec::bound_t &bound, const std::string &title) {
    if (!instance) instance = new render_t(bound, title);
    return instance;
}

void utec::render_t::draw_rectangle(utec::position_t p, utec::dimension_t d, utec::color_t c) {
    sf::RectangleShape s;
    s.setSize({d.width, d.height});
    s.setFillColor(c);
    s.setPosition(p.x, p.y);
    auto& canvas = get_instance()->platform_render;
    canvas.draw(s);
}

void utec::render_t::draw_ellipse(utec::position_t p, utec::dimension_t d, utec::color_t c) {
    sf::CircleShape s;
    s.setRadius(1);
    s.setFillColor(c);
    s.setScale({d.width/2, d.width/2});
    s.setPosition(p.x, p.y);
    auto& canvas = get_instance()->platform_render;
    canvas.draw(s);
}

utec::bound_t utec::render_t::get_limit() {
    auto& canvas = get_instance()->platform_render;
    return {canvas.getSize().x, canvas.getSize().y};
}

utec::platform_render_t &utec::render_t::get_platform_render() {
    return platform_render;
}
