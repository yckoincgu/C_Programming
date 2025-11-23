#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h> 

/* 
 * This is the callback function used by sqlite3_exec 
 * to display results from a SELECT query in table format.
 */
static int callback(void *data, int argc, char **argv, char **azColName) {
    // Calculate column widths
    int *colWidths = (int*)data;
    
    // First row - print column headers
    if(colWidths[0] == 0) {
        // Calculate maximum width for each column
        for(int i = 0; i < argc; i++) {
            colWidths[i] = strlen(azColName[i]);
            if(argv[i] && strlen(argv[i]) > colWidths[i]) {
                colWidths[i] = strlen(argv[i]);
            }
            // Ensure minimum width
            if(colWidths[i] < 8) colWidths[i] = 8;
        }
        
        // Print top border
        printf("+");
        for(int i = 0; i < argc; i++) {
            for(int j = 0; j < colWidths[i] + 2; j++) printf("-");
            printf("+");
        }
        printf("\n");
        
        // Print column headers
        printf("|");
        for(int i = 0; i < argc; i++) {
            printf(" %-*s |", colWidths[i], azColName[i]);
        }
        printf("\n");
        
        // Print separator between header and data
        printf("+");
        for(int i = 0; i < argc; i++) {
            for(int j = 0; j < colWidths[i] + 2; j++) printf("-");
            printf("+");
        }
        printf("\n");
    }
    
    // Print data rows
    printf("|");
    for(int i = 0; i < argc; i++) {
        printf(" %-*s |", colWidths[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    
    return 0;
}

/* 
 * Function to print the bottom border of the table
 */
static void printTableFooter(int argc, int *colWidths) {
    printf("+");
    for(int i = 0; i < argc; i++) {
        for(int j = 0; j < colWidths[i] + 2; j++) printf("-");
        printf("+");
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    int colWidths[10] = {0}; // Array to store column widths

    /* 1. Open Database 
     * If the file doesn't exist, SQLite creates it automatically.
     */
    rc = sqlite3_open("02_test_01.db", &db);

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
    
    fprintf(stdout, "\n--- COMPANY Table Data ---\n");
    
    /* Execute SQL statement 
     * We pass the 'callback' function here to handle the rows returned.
     * We also pass colWidths array to store column widths.
     */
    rc = sqlite3_exec(db, sql, callback, colWidths, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error (Select): %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        // Print the bottom border of the table
        printTableFooter(5, colWidths); // 5 columns in COMPANY table
        fprintf(stdout, "Operation done successfully\n");
    }

    /* 5. Close Database */
    sqlite3_close(db);
    return 0;
}