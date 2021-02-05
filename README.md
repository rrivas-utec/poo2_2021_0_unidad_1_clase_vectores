# Unidad 1: Clase y Vectores 
**curso:** CS1103 - Programación Orientada a Objetos II  
**proyecto:** poo2_2021_0_unidad_1_clase_vectores
##Tarea
1. Modificar el programa de modo que permita cambiar el color de las figuras si ambas colisionan
2. Modificar el programa de modo si un elipse y un rectangulo colisionaran entonces debia removerse del programa una de las figuras aleatoriamente. 
3. Completar la clase vector para que pueda incluir los metodos insert y erase similares al std::vector

```cpp
  namespace utec {
    template <typename T>
    class vector {
      ...
    public:
      ...
      void insert(size_t index, T item);
      void erase(size_t index);
      ...
    };
```
4. Sobrecargar el operador + en la clase utec::vector de modo que permita concatenar 2 vectores

```cpp
  utec::vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);

  utec::vector<int> v2;
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(6);

  // Generar vector 3
  auto v3 = v1 + v2;
  for (size_t i = 0; i < v3.size(); ++i)
    std::cout << v3[i] << " ";
  std::cout << endl;

  // Generar vector 1
  v1 = v3;
  for (size_t i = 0; i < v1.size(); ++i)
    v1[i] *= 2;

  for (size_t i = 0; i < v1.size(); ++i)
    std::cout << v1[i] << " ";
  std::cout << endl;

  for (size_t i = 0; i < v3.size(); ++i)
    std::cout << v3[i] << " ";
  std::cout << endl;
  
```
