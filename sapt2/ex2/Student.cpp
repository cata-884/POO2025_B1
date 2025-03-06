#include "Student.h"
void Student::setName(const char* settedName) {
	int i = 0;
	while (i<49 && settedName[i] != '\0') {
		this->name[i] = settedName[i];
		i++;
	}
	this->name[i] = '\0';
}
char* Student::getName() {
	char* result = (char*)malloc(50);
	int i = 0;
	while (this->name[i] != '\0') {
		result[i] = this->name[i];
		i++;
	}
	result[i] = '\0';
	return result;
}
void Student::setGradeMath(float n) {
	if (n >= 1 && n <= 10) this->grades[0] = n;
}
float Student::getGradeMath() {
	return this->grades[0];
}
void Student::setGradeEnglish(float n) {
	if (n >= 1 && n <= 10) this->grades[1] = n;
}
float Student::getGradeEnglish() {
	return this->grades[1];
}
void Student::setGradeHistory(float n) {
	if (n >= 1 && n <= 10) this->grades[2] = n;
}
float Student::getGradeHistory() {
	return this->grades[2];
}
float Student::getAverageGrade() {
	return (getGradeEnglish() + getGradeHistory() + getGradeMath()) / 3.0f;
}
