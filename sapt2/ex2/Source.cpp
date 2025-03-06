#include<iostream>
#include "Student.h"
#include "Compare.h"
using namespace std;


int main() {
    Student *s1 = new Student(), * s2 = new Student();
    //student mate-info
    s1->setName("Maricica");
    s1->setGradeEnglish(5.3f);
    s1->setGradeHistory(3.2f);
    s1->setGradeMath(10.0f);
    //student litere
    s2->setName("Bartolomeu");
    s2->setGradeEnglish(9.9f);
    s2->setGradeHistory(8.3f);
    s2->setGradeMath(1.7f);

    char* nume = s1->getName();
    printf("%s \n", nume);
    int s1Math = s1->getGradeMath();
    printf("%d \n", s1Math);
    printf("rezultatul compararii numelor: %d\n", cmpName(*s1, *s2));
    delete s1;
    delete s2;
    return 0;
}
