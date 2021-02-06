//
// Created by rudri on 2/3/2021.
//

#include "shape.h"
#include "render.h"

void utec::rectangle_t::draw() {
    render_t::draw_rectangle(position, dimension, color);
}

void utec::rectangle_t::move() {
    position.x += velocity.vx;
    position.y += velocity.vy;
}

void utec::ellipse_t::draw() {
    render_t::draw_ellipse(position, dimension, color);
}

void utec::ellipse_t::move() {
    position.x += velocity.vx;
    position.y += velocity.vy;
}

void utec::bounce_wall(utec::shape_t *a) {
    auto limit = render_t::get_limit();
    if (a->position.x < 0 ||
        a->position.x + a->dimension.width > limit.lim_x)
        a->velocity.vx *= -1;
    if (a->position.y < 0 ||
        a->position.y + a->dimension.height > limit.lim_y)
        a->velocity.vy *= -1;
}

bool utec::have_collided(utec::shape_t *a, utec::shape_t *b) {
    return false;
}

void utec::bounce(utec::shape_t *a, utec::shape_t *b) {

}
