//
// Created by cata-884 on 3/6/25.
//

#include "MovieSeries.h"
#include<stdio.h>
void swap(Movie** a, Movie** b) {
    Movie* temp = *a;
    *a = *b;
    *b = temp;
}
void MovieSeries::init() {
    for(int i=0; i<size; i++) {
        this->movies[i] = nullptr;
    }
}

void MovieSeries::add(Movie *movie) {
    int i =0;
    while(i<size && this->movies[i]!=nullptr) {
        i++;
    }
    this->movies[i] = movie;
}
void heapify(Movie** movies, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && movies[left] && movies[largest] &&
        movies[left]->get_passed_years() > movies[largest]->get_passed_years()) {
        largest = left;
        }

    if (right < n && movies[right] && movies[largest] &&
        movies[right]->get_passed_years() > movies[largest]->get_passed_years()) {
        largest = right;
        }

    if (largest != i) {
        swap(&movies[i], &movies[largest]);
        heapify(movies, n, largest);
    }
}

void MovieSeries::sort() {
    // Build a max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(movies, size, i);
    }

    // Perform heap sort
    for (int i = size - 1; i >= 1; i--) {
        swap(&movies[0], &movies[i]);
        heapify(movies, i, 0);
    }
}

void MovieSeries::print() {
    for (int i = 0; i < size; i++) {
        if (movies[i]) {
            printf("%s | Year: %d | IMDB: %.1f | Length: %d | Passed Years: %d\n",
                   movies[i]->get_name(),
                   movies[i]->get_year(),
                   movies[i]->get_score(),
                   movies[i]->get_length(),
                   movies[i]->get_passed_years());
        }
    }
}

