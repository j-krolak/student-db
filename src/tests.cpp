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

TEST(CheckStructer, CanSaveDB){
    {
        Database db2 ("db-ut.txt");
        db2.insert(johnny);
        EXPECT_TRUE(db2.saveData());
    }

    {
        Database db2 ("db-ut.txt");
        EXPECT_EQ(db2.toString(), "ID  Name    LastName  Address                       Pesel        Gender\n1   Johnny  Pancake   4 Coffee Street, Choco C2315  21054960541  Male\n");
    }
}
