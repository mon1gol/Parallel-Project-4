#ifndef SCHOOLDAY_H
#define SCHOOLDAY_H

#include <vector>
#include "Lesson.h"

class SchoolDay{
public:
	std::string subject;
	std::vector<Lesson> lessons;

	SchoolDay(const std::vector<Lesson>& lesson, const std::string& subject);
};
#endif

