#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "bst.h"

/**
 * Inserts a new node into the right position
 * @param a pointer to a parent node and a pointer to the record
 * @return a pointer to the complete bst with a new child inserted
 */
struct bst_node* insert(struct bst_node* parent, struct record* record){
  char *key = record->name;
  struct bst_node **insert_location = &parent;

  // find the right insertion point
  while(*insert_location){
    if(strcmp(key, (*insert_location)->key) < 0){
      insert_location = &((*insert_location)->left);
    } else if (strcmp(key, (*insert_location)->key) > 0) {
      insert_location = &((*insert_location)->right);
    } else {
      insert_location = &((*insert_location)->equal);
    }
  }

  // allocate memory for new node
  *insert_location = (struct bst_node*) malloc(sizeof(struct bst_node));

  // inserts new node
  (*insert_location)->left = NULL;
  (*insert_location)->right = NULL;
  (*insert_location)->equal = NULL;

  (*insert_location)->key = (char *) malloc(strlen(key) * sizeof(char) + 1);
  strcpy((*insert_location)->key, key);

  (*insert_location)->record = record;

  return parent;
}

struct record* search(struct bst_node* parent, char* key){
  int comp;
  int comp_count;
  struct bst_node **curr_location = &parent;
  struct bst_node **next_location;

  comp_count = 0;
  do {
    comp = strcmp(key, (*curr_location)->key);
    comp_count++;

    if(comp < 0){
      next_location = &((*curr_location)->left);
    } else if(comp > 0) {
      next_location = &((*curr_location)->right);
    } else {
      next_location = &((*curr_location)->equal);
    }

    if(*next_location){
      curr_location = next_location;
    }
  } while(*next_location);

  printf("%s --> %i\n", key, comp_count);

  if(strcmp(key, (*curr_location)->key) == 0){
    return (*curr_location)->record;
  } else {
    return NULL;
  }
}

// frees a tree given the top node
void free_tree(struct bst_node* parent){
  if(!parent){
    return;
  }

  free_tree(parent->left);
  free_tree(parent->equal);
  free_tree(parent->right);

  free_record(parent->record);
  free(parent->key);
  free(parent);
}
