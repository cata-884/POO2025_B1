//
// Created by cata-884 on 3/6/25.
//
#include "Compare.h"
#include <string.h>
int movie_compare_name(Movie &m1, Movie &m2) {
    int n = strcmp(m1.get_name(), m2.get_name());
    if(n==0) return 0;
    if(n>0) return 1;
    return -1;
}
int movie_compare_year(Movie &m1, Movie &m2) {
    if(m1.get_year()==m2.get_year()) return 0;
    else if (m1.get_year()>m2.get_year()) return 1;
    return -1;
}
int movie_compare_score(Movie &m1, Movie &m2) {
    if(m1.get_score()==m2.get_score()) return 0;
    else if (m1.get_score()>m2.get_score()) return 1;
    return -1;
}
int movie_compare_length(Movie &m1, Movie &m2) {
    if(m1.get_length()==m2.get_length()) return 0;
    else if (m1.get_length()>m2.get_length()) return 1;
    return -1;
}
int movie_compare_passed_years(Movie &m1, Movie &m2) {
    if(m1.get_passed_years()==m2.get_passed_years()) return 0;
    else if (m1.get_passed_years()>m2.get_passed_years()) return 1;
    return -1;
}