// https://www.devdungeon.com/content/compiling-sqlite3-c
#include <sqlite3.h>
#include <iostream>
#include "sqlite3.h"
using namespace std;

int main()
{
    char* err;
    sqlite3* mydb;	//the object to be used in manupulating the database
    sqlite3_stmt* stmt; //capturing the database in a spreadsheet-like manner
    sqlite3_open("test.db", &mydb); //opens the database, or if not present creates it

    int rc= sqlite3_exec(mydb,"CREATE TABLE IF NOT EXISTS cit(x1 INT, x2 INT, name varchar(100));",NULL, NULL, &err);
    //the if block reports error to us, in the running of sqlite3_exec routine, if any
    if (rc != SQLITE_OK) {
    cout<< "ERROR: " << err << endl;
    }
    for (int i = 0; i < 10; i++) {
        string query = "INSERT into cit VALUES (12, 15, 'boss');"; //prepare the values to be inserted
        cout << "The querry carries: "<<query <<"\n";
        rc = sqlite3_exec(mydb, query.c_str(), NULL, NULL, &err); //perform the actual insertion
        if (rc != SQLITE_OK) {
            cout<< "INSERT ERROR: " << err << endl;
        }
    }
    //to read from the db and display the results
    sqlite3_prepare_v2(mydb, "SELECT x1, x2, NAME FROM cit", -1, &stmt,0); //prepares the sql statement for evaluation.
    int a1, a2;
    const unsigned char* myname;
    while (sqlite3_step(stmt) != SQLITE_DONE){
        a1 = sqlite3_column_int(stmt,0);
        a2 = sqlite3_column_int(stmt,1);
        myname = sqlite3_column_text(stmt,2);
        cout << "ai is:" << a1 <<" a2 is:" << a2 << "  Name is: "<<myname <<endl;
    }
    sqlite3_close(mydb);

    return 0;
}
