#ifndef DNEVNIK_H
#define DNEVNIK_H
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "constants.h"
#include "Schedule.h"


class Dnevnik
{
public:
	Dnevnik(std::string name_student, std::string surname_student, const Schedule schedule);

	void setOtsenka(const std::string& subject, int lessonNumber, const std::string& newOtsenka, std::string dayOfWeek);
	void dnevnikRoditelam();
	~Dnevnik();

	std::string name_student;
	std::string surname_student;
	Schedule schedule;
};
#endif
