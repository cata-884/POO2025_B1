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
    Canvas(int w,int h);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};



#endif //CANVAS_H
