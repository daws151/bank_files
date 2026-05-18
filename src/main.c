#include "input_file_reader.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Error, missing input file. Add filename to args.");
  }

  else {
    input_file_reader(argc, argv);
  }

  return 0;
};
