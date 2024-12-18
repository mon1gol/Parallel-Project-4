#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Lesson.h"
#include "Dnevnik.h"

class Teacher
{
private:
	const double PROBABILITY_CALLING_STUDENT = 0.2;
	static const int NUM_STUDENTS_ANSWER = 5;

	std::random_device _rd;
	std::mt19937 _gen;
	std::vector<bool> _answered;

public:
	std::string name;
	std::vector<Dnevnik>& dnevniki;

	Teacher(const std::string& name, std::vector<Dnevnik>& dnevniki);
	void ÑonductLesson(std::string day_name, const Lesson lesson, std::vector<Student>& students);
	Student* GetNextStudent(std::vector<Student>& students, const std::vector<bool>& answered, bool isReverse);
	//void AssignGrade(Student& student, const std::string& subject, int lessonNumber, const std::string& day);

};
#endif