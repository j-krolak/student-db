#pragma once
#include "student.hpp"
#include <vector>
#include <fstream>

class Database{
public:
    Database()=default;
    Database(std::string dbPath);
    ~Database();

    bool insert(const Student & student);
    int find(const Student & student);
    bool saveData();
    std::string toString();

private:
    std::vector<Student> students;
    std::string path;
    void algin(std::string & db);
    bool loadData();
};