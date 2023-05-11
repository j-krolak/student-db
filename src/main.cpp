#include <iostream>
#include "student.hpp"
#include "database.hpp"

Student johnny {
    "Johnny", 
    "Pancake", 
    "4 Coffee Street, Choco C2315",
    "21054960541",
    Gender::Male
};


Student sharon {
    "Sharon", 
    "Pancake", 
    "3 Frites , Choco C215",
    "11054960541",
    Gender::Female
};


Database db;

int main(){
    db.insert(johnny);
    db.insert(sharon);
    std::cout << db.toString() << std::endl; 
    return 0;
}