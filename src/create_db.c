#include "../sqlite-src-3510300/sqlite3.h"
#include <stdio.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
  }
}
