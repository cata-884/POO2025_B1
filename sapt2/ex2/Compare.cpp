#include "Compare.h"
#include<stdio.h>
int cmpName(Student& s1, Student& s2)
{
	char* name1 = s1.getName(); 
    char* name2 = s2.getName();
	int i = 0;
	while (name1[i] != '\0' && name2[i] != '\0') {
        if(name1[i]>name2[i]) return 1;
        else if(name1[i]<name2[i]) return -1;
        i++;
    }
    if (name1[i] == '\0' && name2[i] == '\0') return 0;
	else if (name2[i] == '\0') return 1;
    return -1;

}

int cmpMathGrade(Student& s1, Student& s2)
{
	float grade1 = s1.getGradeMath(), grade2 = s2.getGradeMath();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}

int cmpEnglishGrade(Student& s1, Student& s2)
{
	float grade1 = s1.getGradeEnglish(), grade2 = s2.getGradeEnglish();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}

int cmpHistoryGrade(Student& s1, Student& s2)
{
	float grade1 = s1.getGradeHistory(), grade2 = s2.getGradeHistory();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}

int cmpAverage(Student& s1, Student& s2)
{
	float grade1 = s1.getAverageGrade(), grade2 = s2.getAverageGrade();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}
