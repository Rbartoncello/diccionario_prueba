cmake_minimum_required(VERSION 3.20)
project(Diccionario)

set(CMAKE_CXX_STANDARD 14)

add_executable(Diccionario main.cpp edificio.cpp edificio.h diccionario.cpp diccionario.h nodo.cpp nodo.h
        edificios.txt receta.cpp receta.h piedra.cpp piedra.h madera.cpp madera.h metal.cpp metal.h)
