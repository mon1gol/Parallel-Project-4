#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Schedule.h"

const Schedule SCHEDULE({
	SchoolDay({
		Lesson("Математика", 1, ""),
		Lesson("Русский язык", 2, ""),
		Lesson("Биология", 3, ""),
		Lesson("Физика", 4, ""),
		Lesson("История", 5, "")
	}, "Понедельник"),
	SchoolDay({
		Lesson("Химия", 1, ""),
		Lesson("География", 2, ""),
		Lesson("Информатика", 3, ""),
		Lesson("Литература", 4, ""),
		Lesson("Обществознание", 5, "")
	}, "Вторник"),
	SchoolDay({
		Lesson("Английский язык", 1, ""),
		Lesson("Физкультура", 2, ""),
		Lesson("Математика", 3, ""),
		Lesson("Искусство", 4, ""),
		Lesson("Химия", 5, "")
	}, "Среда"),
	SchoolDay({
		Lesson("Биология", 1, ""),
		Lesson("Русский язык", 2, ""),
		Lesson("География", 3, ""),
		Lesson("Физика", 4, ""),
		Lesson("Информатика", 5, "")
	}, "Четверг"),
	SchoolDay({
		Lesson("История", 1, ""),
		Lesson("Литература", 2, ""),
		Lesson("Английский язык", 3, ""),
		Lesson("Обществознание", 4, ""),
		Lesson("Физкультура", 5, "")
	}, "Пятница"),
	SchoolDay({
		Lesson("Математика", 1, ""),
		Lesson("Физика", 2, ""),
		Lesson("Химия", 3, ""),
		Lesson("История", 4, ""),
		Lesson("Русский язык", 5, "")
	}, "Суббота")
});

const std::vector<std::string> TEACHER_WELCOME_PHRASES = {
	"Добрый день! сейчас урок: ",
	"Салам Алейкум! сейчас урок: ",
	"Фака Макафо! сейчас урок: ",
	"Здравствуйте! сейчас урок: "
};

const std::vector<std::string> TEACHER_CALL_PHRASES = {
	"Вызываю тебя к доске",
	"Иди к доске",
	"Подойди к доске, пожалуйста"
};

const std::vector<std::string> TEACHER_OTSENKA_PHRASES = {
	"Поздравляю! Твоя оценка: ",
	"Неплох! Твоя оценка: ",
	"Харош! Твоя оценка: ",
	"Сосал! Твоя оценка: "
};

const std::vector<std::string> STUDENT_WELCOME_PHRASES = {
	"Дарова!",
	"Привет! Сосал?",
	"Салам!"
};

const std::vector<std::string> STUDENT_RESPONSES = {
	"Да, я готов!",
	"Сейчас подойду!",
	"Спасибо за вызов!"
};

#endif


