//
// Created by rudri on 2/3/2021.
//

#include "shape.h"
#include "render.h"

void utec::rectangle_t::draw() {
    render_t::draw_rectangle(position, dimension, color);
}

void utec::rectangle_t::move() {

}

void utec::ellipse_t::draw() {
    render_t::draw_ellipse(position, dimension, color);
}

void utec::ellipse_t::move() {

}
