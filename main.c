#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "record.h"

struct bst_node* makedict(char *datafile);

int main(int argc, char *argv[]){
  char datafile[128];
  char outputfile[128];
  struct bst_node* dictionary;
  struct record* result;

  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  dictionary = makedict(datafile);

  result = search(dictionary, "Sofiya Aleksandrovna Velikaya");

  free_tree(dictionary);

  return 0;
}

// given the filename of an input file, populates a BST with data in file
struct bst_node* makedict(char *datafile){
  FILE *file = fopen(datafile, "r");
  char rows[MAX_LINE];

  struct bst_node* dictionary = NULL;

  while (fgets(rows, MAX_LINE, file)){
    char* row = strdup(rows);
    struct record* record = read_row(row);

    dictionary = insert(dictionary, record);

    free(row);
  }
  return dictionary;
}
