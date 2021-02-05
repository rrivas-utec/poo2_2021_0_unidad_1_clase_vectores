//
// Created by rudri on 2/3/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_VECTOR_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_VECTOR_H

#include "shape.h"

namespace utec {

    using T = shape_t*;

    class vector {
        T* data {};
        size_t length {};
    public:
        vector() = default;

        // Constructor copia (Caso #1)
        vector(const vector& other) {
            lenght = other.length;
            data = new T[length];
            for(size_t i = 0; i < length; ++i)
                data[i] = other.data[i];
        }

        // Asignacion de un vector por copy (Caso #2)
        vector& operator= (const vector& other) {
            delete[] data;
            lenght = other.length;
            data = new T[length];
            for(size_t i = 0; i < length; ++i)
                data[i] = other.data[i];
            return *this;
        }

        // Constructor move (Caso #1)
        vector(vector&& other) noexcept { // && referencia rvalue
            lenght = other.length;
            data = other.data;
            other.data = nullptr;
        }

        // Asignacion de un vector por move (Caso #2)
        vector& operator= (vector&& other) noexcept {
            delete[] data;
            lenght = other.length;
            data = other.data;
            other.data = nullptr;
            return *this;
        }

        ~vector() {
            delete[] data;
            length = 0;
        }

        void push_back(const T& item) {

        }

        void pop() {

        }

        [[nodiscard]] size_t size() const {
            return length;
        }

        // Equivalente al Set
        // Ejemplo --> vector[i] = 10
        T& operator[](size_t index) {
            return data[index];
        }

        // Equivalente al get
        // Ejemplo --> cout << vector[i]
        const T& operator[](size_t index) const {
            return data[index];
        }
    };


}

#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_VECTOR_H
