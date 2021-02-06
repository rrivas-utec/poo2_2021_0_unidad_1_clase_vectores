//
// Created by rudri on 2/3/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_VECTOR_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_VECTOR_H

#include "shape.h"
#include "my_algorithm.h"

namespace utec {

    using T = shape_t*;

    class vector {
        T* data {};
        size_t length {};
    public:
        vector() = default;

        // Constructor copia (Caso #1)
        vector(const vector& other) {
            length = other.length;
            data = new T[length];
            copy(other.data, other.data+other.length, data);
        }

        // Asignacion de un vector por copy (Caso #2)
        vector& operator= (const vector& other) {
            delete[] data;
            length = other.length;
            data = new T[length];
            copy(other.data, other.data+other.length, data);
            return *this;
        }

        // Constructor move (Caso #1)
        vector(vector&& other) noexcept { // && referencia rvalue
            length = other.length;
            data = other.data;
            other.data = nullptr;
        }

        // Asignacion de un vector por move (Caso #2)
        vector& operator= (vector&& other) noexcept {
            delete[] data;
            length = other.length;
            data = other.data;
            other.data = nullptr;
            return *this;
        }

        ~vector() {
            delete[] data;
            length = 0;
        }

        void push_back(const T& item) {
            // 1. Reserva length + 1 espacio en temp
            auto temp = new T[length + 1];
            // 2. Copiar de data hacia temp
            copy(data, data+length, temp);
            // 3. Borrar los valores anteriores de data
            delete[] data;
            // 4. Le asigno temp a data
            data = temp;
            // 5. Adiciono el item en data
            data[length] = item;
            // 6. Incremento el tamaño de lenght
            length++;
        }

        void pop() {
            // 1. Reserva length - 1 espacio en temp
            auto temp = new T[length - 1];
            // 2. Copiar de data hacia temp solo los valores hasta length - 1
            copy(data, data+length-1, temp);
            // 3. Eliminar data
            delete [] data;
            // 4. Le asigno temp a data
            data = temp;
            // 5. disminuir el tamaño de lenght
            length--;
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
