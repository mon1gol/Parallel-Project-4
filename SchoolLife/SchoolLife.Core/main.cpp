#include <iostream>
#include "constants.h"
#include "Teacher.h"
#include "Student.h"
#include "Dnevnik.h"
#include "mpi.h"


int main()
{
    std::vector<Student> students;
    std::vector<Dnevnik> dnevniki;
    
    students.push_back(Student("Иван", "Иванов", ""));
    students.push_back(Student("Петр", "Петров", ""));
    students.push_back(Student("Сидор", "Сидоров", ""));

    dnevniki.push_back(Dnevnik("Иван", "Иванов", SCHEDULE));
    dnevniki.push_back(Dnevnik("Петр", "Петров", SCHEDULE));
    dnevniki.push_back(Dnevnik("Сидор", "Сидоров", SCHEDULE));

    Teacher t("Элеонора Артуровна", dnevniki);

    for (int i = 0; i < SCHEDULE.school_dyas.size(); i++) {
        for (int j = 0; j < SCHEDULE.school_dyas[i].lessons.size(); j++) {
            t.СonductLesson(SCHEDULE.school_dyas[i].subject, SCHEDULE.school_dyas[i].lessons[j], students);
        }
    }

    for (size_t i = 0; i < dnevniki.size(); i++)
    {
        dnevniki[i].dnevnikRoditelam();
    }

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
