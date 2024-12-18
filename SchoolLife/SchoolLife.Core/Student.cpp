#include "Student.h"
#include "constants.h"
#include <random>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <mpi.h>

Student::Student(const std::string& s, const std::string& n, const std::string& p)
    : surname(s), name(n), patronymic(p), _gen(_rd()) {
    std::string file_name = surname + "_" + name + "_dialog.txt";
    std::remove(file_name.c_str());
    _log_file.open(surname + "_" + name + "_dialog.txt", std::ios::out | std::ios::app);
}

/// <summary>
/// Генерирует оценку, которую получит ученик
/// </summary>
/// <returns></returns>Возвращает эту оценку
int Student::GetRandomGrade() {
    std::uniform_int_distribution<> dis(0, grades_probabilities.size() - 1);
    return grades_probabilities[dis(_gen)];
}

Student::Student(Student&& other) noexcept
    : name(std::move(other.name)), surname(std::move(other.surname)), _log_file(std::move(other._log_file)) {
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        surname = std::move(other.surname);
        _log_file = std::move(other._log_file);
    }
    return *this;
}

/// <summary>
/// Получает ответ учителя, если это вызов, то отвечает
/// </summary>
/// <param name="message"></param>
void Student::ListenToTeacher() {
    char message[100];
    MPI_Recv(message, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    std::string receivedMessage = message;
    
    if (receivedMessage.find("сейчас урок") != std::string::npos)
    {
        LogResponse(receivedMessage);

        if (std::uniform_real_distribution<>(0.0, 1.0)(_gen) < 0.4)
        {
            std::string response = STUDENT_WELCOME_PHRASES[rand() % STUDENT_WELCOME_PHRASES.size()];
            LogResponse(response);
            MPI_Send(response.c_str(), response.length() + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
        }
    }

    if (receivedMessage.find("оценка") != std::string::npos)
    {
        LogResponse(receivedMessage);
    }

    if (receivedMessage.find(surname) != std::string::npos) {
        std::string response = STUDENT_RESPONSES[rand() % STUDENT_RESPONSES.size()];
        LogResponse(receivedMessage);
        LogResponse(response);
        MPI_Send(response.c_str(), response.length() + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    }
}

/// <summary>
/// Записывает диалог
/// </summary>
/// <param name="response"></param>
void Student::LogResponse(const std::string& response) {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);

    std::tm timeInfo;
    localtime_s(&timeInfo, &time);

    _log_file << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << ": " << response << std::endl;
}

Student::~Student() {
    if (_log_file.is_open()) {
        _log_file.close();
    }
}