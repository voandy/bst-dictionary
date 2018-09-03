#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "record.h"

struct bst_node* makedict(char *datafile);
void find_key(struct bst_node* dictionary, char *key, FILE *file);

int main(int argc, char *argv[]){
  char datafile[128];
  char outputfile[128];
  struct bst_node* dictionary;

  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  dictionary = makedict(datafile);

  FILE *file = fopen(outputfile, "w");
  find_key(dictionary, "Danijel Bajlo", file);

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

/**
* searches for a key in the provided bst and outputs record if found
* @param a dictionary, a key to search for and a file to write to
* @return NA
*/
void find_key(struct bst_node* dictionary, char *key, FILE *file){
  struct record* result;
  result = search(dictionary, key);

  fprintf(file, "%s --> ", key);

  if(result) {
    write_result(file, result);
  } else {
    fprintf(file, "NOTFOUND\n");
  }
}
