#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string.h>
#include<stdlib.h>
class Student
{
private:
	char name[50];
	float grades[3]; //math, english, history
public:
	Student() {
		memset(name, 0, sizeof(name));
		memset(grades, 0, sizeof(grades));
	}
	void setName(const char* settedName);
	char* getName();
	void setGradeMath(float n);
	float getGradeMath();
	void setGradeEnglish(float n);
	float getGradeEnglish();
	void setGradeHistory(float n);
	float getGradeHistory();
	float getAverageGrade();
};

#endif