/*
В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
затем (через пробел) – фамилия ученика. Общее число строк в файле не превосходит 100000.
Длина каждой фамилии не превосходит 50 символов.

Необходимо вывести список школьников по классам:
сначала всех учеников 9 класса, затем – 10, затем – 11.
Внутри одного класса порядок вывода фамилий должен быть таким же, как на входе.
*/

#include <iostream>
#include <vector>
#include <sstream>


std::vector<std::vector<std::string>> sort_students(const std::vector<std::pair<int,std::string>>& list)
{
    std::vector<std::vector<std::string>> v2(3);
    for (std::pair<int,std::string> student : list)
        v2[student.first - 9].push_back(student.second);
    return v2;
}


int main()
{
    std::vector<std::pair<int, std::string>> list;
    int year;
    std::string name, str;

    while(std::getline(std::cin, str))
    {
        std::istringstream iss(str);
        std::pair<int, std::string> student;
        if (iss >> year >> name)
        {
            student.first = year;
            student.second = name;
            list.push_back(student);
        }
        else break;
    }

    std::vector<std::vector<std::string>> v2 = sort_students(list);
    for (int i = 9; i < 12; i++)
    {
        for (std::string student_name: v2[i - 9])
            std::cout << i << " " << student_name << std::endl;
    }
    return 0;
}
