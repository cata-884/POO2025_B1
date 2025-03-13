#include "Canvas.h"
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int lines, int columns) : width(lines), height(columns) {
    image = new char*[height];
    for (int i = 0; i < height; i++) {
        image[i] = new char[width];
        for (int j = 0; j < width; j++) {
            image[i][j] = ' ';
        }
    }
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < height && y >= 0 && y < width) {
        image[x][y] = value;
    }
}

void Canvas::set_pixels(int count, ...) {
    va_list list;
    va_start(list, count);

    for (int i = 0; i < count; i++) {
        int x = va_arg(list, int);
        int y = va_arg(list, int);
        char c = static_cast<char>(va_arg(list, int));
        set_pixel(x, y, c);
    }
    va_end(list);
}

void Canvas::clear() {
    if (image) {
        for (int i = 0; i < height; i++) {
            delete[] image[i];
        }
        delete[] image;
        image = nullptr;
    }
}

void Canvas::print() const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << image[i][j];
        }
        std::cout << "\n";
    }
}

