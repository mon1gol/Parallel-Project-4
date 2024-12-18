#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include "SchoolDay.h"

class Schedule
{
public:
	std::vector<SchoolDay> school_dyas;

	Schedule(const std::vector<SchoolDay>& dyas);
};
#endif 

