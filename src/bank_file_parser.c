#include "input_file_reader.h"
#include <stdio.h>
#include <xlsxwriter.h>

typedef struct {
  char date[15];
  char chargeName[100];
  double chargeAmount;
} Charges;

/*void generate_spreadsheet() {
  lxw_workbook *workbook = workbook_new("bank_statements.xlsx");
  lxw_worksheet *worksheet1 = workbook_add_worksheet(workbook, "December");
};*/

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("Error, missing input file. Add filename to args.");
  }

  else {
    input_file_reader(argc, argv);
  }

  return 0;
};
