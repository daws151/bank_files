#include <stdio.h>
#include <string.h>

void read_file() {
  char buffer[1024];
  FILE *file = fopen("dec2025credit.csv", "r");
  if (file == NULL) {
    perror("Error opening file");
  }
  while (fgets(buffer, sizeof(buffer), file)) {
    char *field = strtok(buffer, ",");
    while (field != NULL) {
      printf("Field: %s\n", field);
      field = strtok(NULL, ",");
    }
  }
  fclose(file);
}

int main() { read_file(); }
