#include <iostream>
#include "student.hpp"
#include "database.hpp"

using namespace std;

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


Database db("db.txt");

int main(){
    int option = 0;
    cin >> option;
    if(option == 0){
        db.insert(johnny);
        db.insert(sharon);
        std::cout << db.toString() << std::endl;
        db.saveData(); 
    }
    else{
        std::cout << db.toString() << std::endl;
    }

    return 0;
}