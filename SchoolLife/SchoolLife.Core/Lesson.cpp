#include "Lesson.h"


Lesson::Lesson(const std::string& sub, const int num, std::string otsenka)
	: subject(sub), number(num), otsenka(otsenka){}


void Lesson::setOtsenka(const std::string& newOtsenka) {
	otsenka = newOtsenka;
}