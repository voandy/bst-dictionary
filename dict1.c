#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "bst.h"
#include "entry.h"

int main(int argc, char *argv[]){
  char datafile[128];
  char outputfile[128];

  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  FILE* data = fopen(datafile, "r");
  char rows[MAX_LINE];

  while (fgets(rows, MAX_LINE, data)){
    char* row = strdup(rows);
    printf("%s\n", row);
    entry_t* entry = read_row(row);
    free(row);
    free(entry);
  }

  return 0;
}
