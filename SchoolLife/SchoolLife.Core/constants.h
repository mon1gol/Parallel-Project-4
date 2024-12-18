#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Schedule.h"

const Schedule SCHEDULE({
	SchoolDay({
		Lesson("����������", 1, ""),
		Lesson("������� ����", 2, ""),
		Lesson("��������", 3, ""),
		Lesson("������", 4, ""),
		Lesson("�������", 5, "")
	}, "�����������"),
	SchoolDay({
		Lesson("�����", 1, ""),
		Lesson("���������", 2, ""),
		Lesson("�����������", 3, ""),
		Lesson("����������", 4, ""),
		Lesson("��������������", 5, "")
	}, "�������"),
	SchoolDay({
		Lesson("���������� ����", 1, ""),
		Lesson("�����������", 2, ""),
		Lesson("����������", 3, ""),
		Lesson("���������", 4, ""),
		Lesson("�����", 5, "")
	}, "�����"),
	SchoolDay({
		Lesson("��������", 1, ""),
		Lesson("������� ����", 2, ""),
		Lesson("���������", 3, ""),
		Lesson("������", 4, ""),
		Lesson("�����������", 5, "")
	}, "�������"),
	SchoolDay({
		Lesson("�������", 1, ""),
		Lesson("����������", 2, ""),
		Lesson("���������� ����", 3, ""),
		Lesson("��������������", 4, ""),
		Lesson("�����������", 5, "")
	}, "�������"),
	SchoolDay({
		Lesson("����������", 1, ""),
		Lesson("������", 2, ""),
		Lesson("�����", 3, ""),
		Lesson("�������", 4, ""),
		Lesson("������� ����", 5, "")
	}, "�������")
});

const std::vector<std::string> TEACHER_WELCOME_PHRASES = {
	"������ ����! ������ ����: ",
	"����� �������! ������ ����: ",
	"���� ������! ������ ����: ",
	"������������! ������ ����: "
};

const std::vector<std::string> TEACHER_CALL_PHRASES = {
	"������� ���� � �����",
	"��� � �����",
	"������� � �����, ����������"
};

const std::vector<std::string> TEACHER_OTSENKA_PHRASES = {
	"����������! ���� ������: ",
	"������! ���� ������: ",
	"�����! ���� ������: ",
	"�����! ���� ������: "
};

const std::vector<std::string> STUDENT_WELCOME_PHRASES = {
	"������!",
	"������! �����?",
	"�����!"
};

const std::vector<std::string> STUDENT_RESPONSES = {
	"��, � �����!",
	"������ �������!",
	"������� �� �����!"
};

#endif


