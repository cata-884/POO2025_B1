//
// Created by cata-884 on 3/6/25.
//

#ifndef MOVIESERIES_H
#define MOVIESERIES_H
#include "Movie.h"
#define size 16
class MovieSeries {
private:
    Movie *movies[16];
public:
    MovieSeries() {
        for(int i=0; i<size; i++) {
            this->movies[i] = nullptr;
        }
    }
    void init();
    void add(Movie *movie);
    void sort();
    void print();
};



#endif //MOVIESERIES_H
