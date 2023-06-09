#include "student.hpp"

using namespace std;

Student::Student(string name, string lastName, string address, string pesel, Gender gender):
name{name}, lastName{lastName},  address{address}, pesel{pesel}, gender{gender}
{}

bool Student::operator==(const Student & student){
    unsigned char isEqual = 1;
    isEqual &= name == student.name;
    isEqual &= lastName == student.lastName;
    isEqual &= pesel == student.pesel;
    isEqual &= address == student.address;
    isEqual &= gender == student.gender;

    return isEqual>0;
}

std::string Student::toString(bool convertGender){
    string student =  name + ';' + lastName + ';' + pesel + ';' + address + ';';
    if(convertGender){
        return student + to_string(static_cast<int>(gender));
    }

    switch(gender){
        case Gender::Female:
            student += "Female";
            break;
        case Gender::Male:
            student += "Male";
            break;
    }

    return student;
}
