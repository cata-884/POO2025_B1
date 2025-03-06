//
// Created by cata-884 on 3/6/25.
//

#include "Movie.h"
#include<string.h>
#include<stdlib.h>
void Movie::set_name(const char *nume) {
    strcpy(this->name, nume);
}

char * Movie::get_name() {
    return this->name;
}

void Movie::set_year(int n) {
    this->release_year = n;
}

int Movie::get_year() {
    return this->release_year;
}

void Movie::set_score(double n) {
    this->IMDB_score = n;
}

double Movie::get_score() {
    return this->IMDB_score;
}

void Movie::set_length(int n) {
    this->movie_length = n;
}

int Movie::get_length() {
    return this->movie_length;
}
int Movie::get_passed_years() {
    return current_year-get_year();
}

