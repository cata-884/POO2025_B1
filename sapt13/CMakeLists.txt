cmake_minimum_required(VERSION 3.29)
project(catalog)

set(CMAKE_CXX_STANDARD 20)

add_executable(catalog main.cpp
        Romana.h
        Matematica.h
        Materie.h
        Infomatica.h
        Student.h
        Catalog.h
        Catalog.cpp
        CatalogEn.h
        CatalogRo.h
)
