#include "../../sqlite-src-3510300/sqlite3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

sqlite3 *db;

typedef struct {
  char date[15];
  char chargeName[200];
  double chargeAmount;
  double chargeCumulative;
} Charges;

int db_connect() {
  int return_code = sqlite3_open("bankingdb.db", &db);
  if (return_code) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return EXIT_FAILURE;
  } else {
    printf("Opening database successfully\n");
  }

  return EXIT_SUCCESS;
}

void create_or_load_table() {
  char *err_msg = 0;
  const char *sql = "CREATE TABLE IF NOT EXISTS Banking("
                    "ID INTEGER PRIMARY KEY, "
                    "Date TEXT, "
                    "ChargeName TEXT, "
                    "ChargeAmount REAL, "
                    "Cumulative REAL);";
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
}

void write_to_table(char *date, char *chargeName, double chargeAmount) {
  char *err_msg = 0;
  char *sql = "INSERT INTO Banking (Date, ChargeName, ChargeAmount) VALUES";
  int rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  sqlite3_close(db);
}

void field_splitter(char buffer[]) {
  Charges charges;

  char *token = strtok(buffer, ",");
  if (token != NULL) {
    strcpy(charges.date, token);

    token = strtok(NULL, ",");
    if (token != NULL)
      strcpy(charges.chargeName, token);

    token = strtok(NULL, ",");
    if (token != NULL)
      charges.chargeAmount = strtod(token, NULL);

    token = strtok(NULL, ",");
    if (token != NULL)
      charges.chargeCumulative = strtod(token, NULL);

    printf(
        "date: %s, chargeName: %s, chargeAmount: %.2f, chargeCumulative: %.2f",
        charges.date, charges.chargeName, charges.chargeAmount,
        charges.chargeCumulative);

    write_to_table(charges.date, charges.chargeName, charges.chargeAmount);
  }
}

void input_file_reader(int num_files, char *file_name[]) {
  char buffer[1024];

  for (int file_index = 1; file_index < num_files; file_index++) {
    FILE *fptr = fopen(file_name[file_index], "r");
    if (fptr == NULL) {
      printf("Error: Unable to open %s\n", file_name[file_index]);
      exit(-1);
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
      db_connect();
      create_or_load_table();
      field_splitter(buffer);
    }

    fclose(fptr);
  }
}
