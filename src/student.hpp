#pragma once
#include <string>

enum class Gender{
    Male, Female
};

class Student{
    friend class Database;
public:
    Student(std::string name, std::string lastName, std::string address, std::string pesel, Gender gender);
    bool operator==(const Student & student);
    std::string toString();

private:
    Gender gender;
    std::string name;
    std::string lastName;
    std::string address;
    std::string pesel;
};