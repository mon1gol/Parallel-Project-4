#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>

class Student
{
private:
    std::random_device _rd;
    std::mt19937 _gen;
    std::ofstream _log_file;

public:
    std::string surname;
    std::string name;
    std::string patronymic;
    std::vector<int> grades_probabilities = { 2, 3, 4, 5 };

    Student(const std::string& s, const std::string& n, const std::string& p);
    int GetRandomGrade();
    void ListenToTeacher(const std::string& message);
    void LogResponse(const std::string& response);
    Student(const Student&) = delete;
    Student& operator=(const Student&) = delete;
    Student(Student&& other) noexcept;
    Student& operator=(Student&& other) noexcept;
    ~Student();

};
#endif

