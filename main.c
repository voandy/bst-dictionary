#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"
#include "record.h"

struct bst_node *makedict(char *datafile);

int main(int argc, char *argv[]){
  char datafile[MAX_STR];
  char outputfile[MAX_STR];
  char key[MAX_STR];
  struct bst_node *dictionary;

  // read in input and output file names
  strcpy(datafile, argv[1]);
  strcpy(outputfile, argv[2]);

  // populate dictionary using input file
  dictionary = makedict(datafile);

  // open output files
  FILE *file = fopen(outputfile, "w");

  // search for keys in dictionary
  while (fgets(key, MAX_STR, stdin) != NULL){
    // removes the line break from key if present
    if(key[strlen(key) - 1] == '\n'){
      key[strlen(key) - 1] = '\0';
    }
    // searchs for and outputs keys
    search(dictionary, key, file);
  }

  // frees the dictionary
  free_tree(dictionary);
  return 0;
}

// given the filename of an input file, populates a BST with data from file
struct bst_node * makedict(char *datafile){
  FILE *file = fopen(datafile, "r");
  char rows[MAX_LINE];

  struct bst_node *dictionary = NULL;

  // grabs each row frin the file and coverts it to a record
  while (fgets(rows, MAX_LINE, file)){
    char* row = strdup(rows);
    struct record *record = read_row(row);

    // inserts the record into dictionary
    dictionary = insert(dictionary, record);

    free(row);
  }
  return dictionary;
}
