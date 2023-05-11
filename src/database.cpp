#include "database.hpp"
#include <math.h>
#include <iostream>

using namespace std;

bool Database::insert(const Student& student){
    if(find(student) >= 0){
        return false;
    }

    try{
        students.push_back(student);
    }
    catch(...){
        return false;
    }

    return true;
}

int Database::find(const Student& student){
    for(size_t i = 0; i < students.size(); i++){
        if(students[i] == student){
            return i;
        }
    }

    return -1;
}

std::string Database::toString(){
    size_t nameL = 4;
    size_t idL = 2;
    idL = max(to_string(students.size()).size(), idL);

    size_t lastNameL = 8;
    size_t addressL = 6;
    size_t peselL = 11;

    for(auto & s : students){
        nameL = max(nameL, s.name.size());
        lastNameL = max(lastNameL, s.lastName.size());
        addressL = max(addressL, s.address.size());
    }

    size_t baseSize =  idL + nameL + lastNameL + addressL + peselL + 10;
    const string lineBase (baseSize, ' ');

    string db;
    string line;
    line = lineBase;
    line.replace(0, 2, "ID");

    line.replace(idL + 2, 4, "Name");
    line.replace(idL + nameL+ 4, 8, "LastName");
    line.replace(idL + nameL+lastNameL+6, 7,"Address");
    line.replace(idL + nameL+lastNameL+addressL+8, 5, "Pesel");
    db += line + "Gender\n";

    int id = 1;
    for(auto & s : students){
        line = lineBase;
        line.replace(0, to_string(id).size(), to_string(id));

        line.replace(idL + 2, s.name.size(), s.name);
        line.replace(idL + nameL+ 4, s.lastName.size(), s.lastName);
        line.replace(idL + nameL+lastNameL+6, s.address.size(), s.address);
        line.replace(idL + nameL+lastNameL+addressL+8, s.pesel.size(), s.pesel);

        switch (s.gender)
        {  
            case Gender::Female:
                line += "Female";
                break;
            case Gender::Male:
                line += "Male";
                break;
            default:
                line += "None";
                break;
        }

        db += line + '\n';
        id++;
    }

    return db;
}