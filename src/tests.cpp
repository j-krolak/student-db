#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"



Student johnny {
    "Johnny", 
    "Pancake", 
    "4 Coffee Street, Choco C2315",
    "21054960541",
    Gender::Male
};

Database db;


TEST(CheckStructure, CanAddStudentToDB){

    EXPECT_TRUE(db.insert(johnny));
    EXPECT_FALSE(db.insert(johnny));

}

TEST(CheckStructer, CanConvertDBToString){

    EXPECT_EQ(db.toString(), "ID  Name    LastName  Address                       Pesel        Gender\n1   Johnny  Pancake   4 Coffee Street, Choco C2315  21054960541  Male\n");
}