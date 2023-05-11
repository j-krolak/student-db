#pragma once
#include "student.hpp"
#include <vector>

class Database{
public:
    bool insert(const Student & student);
    int find(const Student & student);
    std::string toString();

private:
    std::vector<Student> students;
    void algin(std::string & db);
};