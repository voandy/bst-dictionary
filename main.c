#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "record.h"

int main(int argc, char *argv[]){
  char datafile[128];
  char outputfile[128];

  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  FILE* record = fopen(datafile, "r");
  char rows[MAX_LINE];

  struct bst_node* dictionary;
  dictionary = makedict();

  while (fgets(rows, MAX_LINE, record)){
    char* row = strdup(rows);
    struct record* record = read_row(row);

    print_name_id(record);
    dictionary = insert(dictionary, record);

    free(row);
  }

  free_tree(dictionary);

  return 0;
}
