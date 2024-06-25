#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

// Function to drop existing tables if they exist
void dropTables(sqlite3 *db)
{
    const char *drop_tests_table_sql = "DROP TABLE IF EXISTS tests;";
    const char *drop_summary_table_sql = "DROP TABLE IF EXISTS summary;";

    char *err_msg = nullptr;

    // Drop the tests table
    int rc = sqlite3_exec(db, drop_tests_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error dropping tests table: " << err_msg << endl;
        sqlite3_free(err_msg);
    }

    // Drop the summary table
    rc = sqlite3_exec(db, drop_summary_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error dropping summary table: " << err_msg << endl;
        sqlite3_free(err_msg);
    }
}

// Function to create the tables
void createTables(sqlite3 *db)
{
    const char *tests_table_sql = R"(
        CREATE TABLE IF NOT EXISTS tests (
            name TEXT,
            test_1 INT,
            test_2 INT
        );
    )";

    const char *summary_table_sql = R"(
        CREATE TABLE IF NOT EXISTS summary (
            name TEXT,
            total_score INT
        );
    )";

    char *err_msg = nullptr;

    // Create the tests table
    int rc = sqlite3_exec(db, tests_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error creating tests table: " << err_msg << endl;
        sqlite3_free(err_msg);
    }

    // Create the summary table
    rc = sqlite3_exec(db, summary_table_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error creating summary table: " << err_msg << endl;
        sqlite3_free(err_msg);
    }
}

// Function to insert data into the tests table
void insertData(sqlite3 *db)
{
    const char *insert_sql = R"(
        INSERT INTO tests (name, test_1, test_2) VALUES
        ('Juha', 13, 24),
        ('Julia', 17, 11),
        ('Kioko', 23, 23),
        ('Yoweri', 21, 18),
        ('King', 19, 25);
    )";

    char *err_msg = nullptr;

    int rc = sqlite3_exec(db, insert_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error inserting data into tests table: " << err_msg << endl;
        sqlite3_free(err_msg);
    }
}

// Function to calculate and insert total scores into the summary table
void calculateAndInsertSummary(sqlite3 *db)
{
    const char *calculate_sql = R"(
        INSERT INTO summary (name, total_score)
        SELECT name, (test_1 + test_2) as total_score
        FROM tests;
    )";

    char *err_msg = nullptr;

    int rc = sqlite3_exec(db, calculate_sql, 0, 0, &err_msg);
    if (rc != SQLITE_OK)
    {
        cerr << "Error calculating and inserting summary: " << err_msg << endl;
        sqlite3_free(err_msg);
    }
}

// Function to display the contents of a table
void displayTable(sqlite3 *db, const char *table_name)
{
    string query = "SELECT * FROM " + string(table_name);
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        cerr << "Error preparing statement: " << sqlite3_errmsg(db) << endl;
        return;
    }

    int col_count = sqlite3_column_count(stmt);

    cout << "\nTable: " << table_name << endl;
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        for (int i = 0; i < col_count; i++)
        {
            cout << sqlite3_column_name(stmt, i) << ": " << sqlite3_column_text(stmt, i) << "\t";
        }
        cout << endl;
    }

    sqlite3_finalize(stmt);
}

int main()
{
    sqlite3 *db;
    int rc = sqlite3_open("perform.db", &db);

    if (rc)
    {
        cerr << "Can't open database: " << sqlite3_errmsg(db) << endl;
        return rc;
    }
    else
    {
        cout << "Opened database successfully" << endl;
    }

    dropTables(db);
    createTables(db);
    insertData(db);
    calculateAndInsertSummary(db);

    displayTable(db, "tests");
    displayTable(db, "summary");

    sqlite3_close(db);
    return 0;
}
