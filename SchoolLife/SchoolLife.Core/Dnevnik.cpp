#include "Dnevnik.h"

Dnevnik::Dnevnik(std::string name_student, std::string surname_student, const Schedule schedule)
	: name_student(name_student), surname_student(surname_student), schedule(schedule){}

void Dnevnik::setOtsenka(const std::string& subject, int lessonNumber, const std::string& newOtsenka, std::string dayOfWeek) {
    for (auto& day : schedule.school_dyas) {
        if (day.subject == dayOfWeek) {
            for (auto& lesson : day.lessons) {
                if (lesson.subject == subject && lesson.number == lessonNumber) {
                    lesson.setOtsenka(newOtsenka);
                    return;
                }
            }
        }
    }
}

void Dnevnik::dnevnikRoditelam()
{
    std::string file_name = name_student + "_" + surname_student + "_dnevnik.txt";
    std::remove(file_name.c_str());
    std::ofstream output_file(file_name, std::ios::out | std::ios::app);

    if (!output_file.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи дневника." << std::endl;
        return;
    }

    output_file << "Дневник ученика: " << name_student << " " << surname_student << "\n\n";
    output_file << std::setw(20) << "Предмет"
        << std::setw(10) << "Урок"
        << std::setw(10) << "Оценка" << "\n";
    output_file << "-------------------------------------------\n";

    std::string current_day;

    for (const auto& day : schedule.school_dyas) {
        if (current_day != day.subject) {
            current_day = day.subject;
            output_file << "\nДень недели: " << current_day << "\n";
            output_file << "-------------------------------------------\n";
        }

        for (const auto& lesson : day.lessons) {
            output_file << std::setw(20) << lesson.subject
                << std::setw(10) << lesson.number
                << std::setw(10) << lesson.otsenka << "\n";
        }
    }

    output_file << "-------------------------------------------\n";
    output_file.close();
}

Dnevnik::~Dnevnik() {
	
}