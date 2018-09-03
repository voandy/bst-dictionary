#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "entry.h"

int main(int argc, char *argv[]){
  char datafile[128];
  char outputfile[128];

  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  FILE* data = fopen(datafile, "r");
  char rows[MAX_LINE];

  struct bst_node* dictionary;
  dictionary = makedict();

  while (fgets(rows, MAX_LINE, data)){
    char* row = strdup(rows);
    struct entry* entry = read_row(row);
    print_data(entry);

    dictionary = insert(dictionary, entry);

    free(row);
  }

  return 0;
}
