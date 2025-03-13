//
// Created by cata-884 on 3/13/25.
//

#ifndef CANVAS_H
#define CANVAS_H



class Canvas {
private:
    char **image;
    int height, width;
public:
    Canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};



#endif //CANVAS_H
