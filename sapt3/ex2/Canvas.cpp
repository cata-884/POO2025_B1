//
// Created by cata-884 on 3/13/25.
//

#include "Canvas.h"
#include<iostream>
#include<algorithm>
#include<cmath>
Canvas::Canvas(int w, int h) {
    width = w;
    height = h;
    image = new char*[height];
    for(int i=0; i<height; i++) {
        image[i] = new char[width];
    }
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            image[i][j] = ' ';
        }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if((pow(i-x,2) + pow(j-y, 2) >= ray*(ray-1))&&(pow(i-x,2) + pow(j-y, 2) <= ray*(ray+1))){
                    SetPoint(i,j, ch);
            }
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(pow(i-x,2) + pow(j-y, 2) <= ray*ray){
                SetPoint(i,j, ch);
            }
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    if (left > right) std::swap(left, right);
    if (top > bottom) std::swap(top, bottom);

    for (int x = left; x <= right; x++) {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }

    for (int y = top; y <= bottom; y++) {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    if (left > right) std::swap(left, right);
    if (top > bottom) std::swap(top, bottom);
    for(int x=left; x<=right; x++) {
        for(int y=top; y<=bottom; y++) {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if(x>=0 && x<width && y>=0 && y<height) {
        image[x][y] = ch;
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int D = 2*dy-dx;
    int y = y1;
    for(int x=x1; x<=x2; x++) {
        SetPoint(x,y,ch);
        if(D>0) {
            y++;
            D-=2*dx;
        }
        D+=2*dy;
    }
}

void Canvas::Print() {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            std::cout<<image[i][j];
        }
        std::cout<<"\n";
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        delete[] image[i];
    }
    delete[] image;
}
