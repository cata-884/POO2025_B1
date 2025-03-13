#include <iostream>
#include "Canvas.h"
int main() {
    Canvas c = Canvas(1000, 1000);
    c.FillCircle(5, 5, 5, '*');
    c.DrawCircle(15, 5, 5, '*');
    c.DrawLine(30, 30, 20, 20, '*');
    c.DrawRect(50, 50, 100, 100, '*');
    c.DrawRect(200, 200, 500, 500, '*');
    c.FillRect(600, 600, 800, 800, '*');
    c.Print();
    c.Clear();
    return 0;
}
