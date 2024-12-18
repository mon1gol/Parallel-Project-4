#ifndef LESSON_H
#define LESSON_H

#include <string>

class Lesson{
public:
	std::string subject;
	std::string otsenka;
	int number;

	Lesson(const std::string& sub, const int num, std::string otsenka);
	void setOtsenka(const std::string& newOtsenka);
};

#endif
