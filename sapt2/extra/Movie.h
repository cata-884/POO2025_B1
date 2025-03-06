

#ifndef MOVIE_H
#define MOVIE_H


#define current_year 2025

#include<string.h>
class Movie {
private:
    char name[256];
    int release_year;
    double IMDB_score;
    int movie_length;
public:
    Movie() {
        memset(name, 0, sizeof(name));
        release_year = 0;
        IMDB_score = 0;
        movie_length = 0;
    }
    void set_name(const char* nume);
    char* get_name();
    void set_year(int n);
    int get_year();
    void set_score(double n);
    double get_score();
    void set_length(int n);
    int get_length();
    int get_passed_years();
};

#endif //MOVIE_H
