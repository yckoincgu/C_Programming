#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

/* * This is the callback function used by sqlite3_exec 
 * to display results from a SELECT query.
 */
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for(int i = 0; i < argc; i++) {
        /*  It prints two strings separated by an equals sign:
            First %s (azColName[i]): This is the Column Name (e.g., "NAME").
            Second %s (argv[i]): This is the Data Value for that row (e.g., "Paul").
        */
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* 1. Open Database 
     * If the file doesn't exist, SQLite creates it automatically.
     */
    rc = sqlite3_open("02_test.db", &db);

    if(rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* 2. Create SQL statement to Create Table */
    sql = "CREATE TABLE IF NOT EXISTS COMPANY("  \
          "ID INT PRIMARY KEY     NOT NULL," \
          "NAME           TEXT    NOT NULL," \
          "AGE            INT     NOT NULL," \
          "ADDRESS        CHAR(50)," \
          "SALARY         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error (Create Table): %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    /* 3. Create SQL statement to Insert Data 
     * Using 'INSERT OR REPLACE' so you can run this code multiple times without errors.
     */
    sql = "INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
          "INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
          "INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
          "INSERT OR REPLACE INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
          "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error (Insert): %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    /* 4. Create SQL statement to Select/Read Data */
    sql = "SELECT * from COMPANY";
    
    fprintf(stdout, "--- Fetching Data ---\n");
    
    /* Execute SQL statement 
     * We pass the 'callback' function here to handle the rows returned.
     */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error (Select): %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }

    /* 5. Close Database */
    sqlite3_close(db);
    return 0;
}