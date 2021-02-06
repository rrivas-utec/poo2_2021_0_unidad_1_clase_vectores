//
// Created by rudri on 2/5/2021.
//

#ifndef POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_ALGORITHM_H
#define POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_ALGORITHM_H

namespace utec {
    template <typename InputPointer, typename OutputPointer>
    OutputPointer copy(InputPointer in_first, InputPointer in_last, OutputPointer out_first) {
        while (in_first != in_last) *out_first++ = *in_first++;
//        while (in_first != in_last) {
//            *out_first = *in_first;
//            out_first++;
//            in_first++;
//        }
        return out_first;
    }

}

#endif //POO2_2021_0_UNIDAD_1_CLASE_VECTORES_MY_ALGORITHM_H
