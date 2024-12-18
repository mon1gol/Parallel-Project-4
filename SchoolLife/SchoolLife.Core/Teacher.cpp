#include "Teacher.h"
#include "constants.h"
//#include "mpi.h"
#include <random>

Teacher::Teacher(const std::string& name, std::vector<Dnevnik>& dnevniki) 
    : name(name), dnevniki(dnevniki), _gen(_rd()) {}

void Teacher::СonductLesson(std::string day_name, const Lesson lesson, std::vector<Student>& students) {
    int responses = 0;
    std::vector<bool> answered(students.size(), false);
    bool isReverse = std::uniform_real_distribution<>(0.0, 1.0)(Teacher::_gen) < 0.5;

    std::string welcome_message = TEACHER_WELCOME_PHRASES[rand() % TEACHER_WELCOME_PHRASES.size()] + lesson.subject;

    for (size_t i = 0; i < students.size(); i++)
    {
        students[i].ListenToTeacher(welcome_message);
    }

    while (responses < 5)
    {
        Student* student = GetNextStudent(students, answered, isReverse);
        if (student == nullptr) break;

        if (std::uniform_real_distribution<>(0.0, 1.0)(_gen) < 0.2) {
            std::string message = TEACHER_CALL_PHRASES[rand() % TEACHER_CALL_PHRASES.size()] + ": " + student->surname;
            for (int i = 0; i < students.size(); ++i) {
                students[i].ListenToTeacher(message);
            }
            
            int otsenka = student->GetRandomGrade();
            student->ListenToTeacher(TEACHER_OTSENKA_PHRASES[rand() % TEACHER_OTSENKA_PHRASES.size()] + std::to_string(otsenka));

            for (size_t i = 0; i < dnevniki.size(); i++)
            {
                if (dnevniki[i].surname_student == student->name) {
                    dnevniki[i].setOtsenka(lesson.subject, lesson.number, std::to_string(otsenka), day_name);
                }
            }

            
            responses++;
            answered[student - &students[0]] = true;
        }
    }
}

Student* Teacher::GetNextStudent(std::vector<Student>& students, const std::vector<bool>& answered, bool isReverse) {
    if (isReverse) {
        // Обратный порядок
        for (int i = students.size() - 1; i >= 0; i--) {
            if (!answered[i]) {
                return &students[i];
            }
        }
    }
    else {
        // Прямой порядок
        for (size_t i = 0; i < students.size(); i++) {
            if (!answered[i]) {
                return &students[i];
            }
        }
    }
    return nullptr;
}