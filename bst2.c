#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "llist.h"
#include "bst2.h"

/**
 * Inserts a new node into the right position
 * @param a pointer to a bst and a pointer to the record
 * @return a pointer to the complete bst with a new child inserted
 */
struct bst_node * insert(struct bst_node *parent, struct record *record){
  int comp;
  char *key = record->name;
  struct bst_node **insert_location = &parent;

  // find the right insertion point
  while(*insert_location){
    comp = strcmp(key, (*insert_location)->key);

    if(comp < 0){
      insert_location = &((*insert_location)->left);
    } else if (comp > 0) {
      insert_location = &((*insert_location)->right);
    } else {
      // if keys match insert new record into list
      insert_list((*insert_location)->list, record);
      return parent;
    }
  }

  // allocate memory for new node
  *insert_location = (struct bst_node*) malloc(sizeof(struct bst_node));

  // inserts new node
  (*insert_location)->left = NULL;
  (*insert_location)->right = NULL;

  // copies key
  (*insert_location)->key = (char *) malloc(strlen(key) * sizeof(char) + 1);
  strcpy((*insert_location)->key, key);

  // creates and inserts new list to hold record
  struct llist *new = make_list();
  new = insert_list(new, record);
  (*insert_location)->list = new;

  return parent;
}

/**
* searches the given bst for a key printing any and all record with matching
* keys (if any)
* @param a bst, a key and a file to write to
*/
void search(struct bst_node *parent, char *key, FILE *file){
  int comp;
  int comp_count = 0;
  struct bst_node **curr_location = &parent;
  struct bst_node **next_location;

  do {
    comp = strcmp(key, (*curr_location)->key);
    comp_count++;

    if(comp < 0){
      next_location = &((*curr_location)->left);
    } else if(comp > 0) {
      next_location = &((*curr_location)->right);
    } else {
      // match found, output all records in the list
      while((*curr_location)->list->head){
        fprintf(file, "%s --> ", key);
        write_result(file, (*curr_location)->list->head->record);
        fprintf(file, "\n");
        (*curr_location)->list->head = (*curr_location)->list->head->next;
      }
      break;
    }

    // iterate until leaf node is reached
    if(*next_location){
      curr_location = next_location;
    }
  } while(*next_location);

  // print name and number of comparisons to stdout
  printf("%s --> %i\n", key, comp_count);

  // output NOTFOUND to file if no match is found
  if(strcmp(key, (*curr_location)->key) != 0){
    fprintf(file, "%s --> NOTFOUND\n\n", key);
  }
}

// frees a tree given the top node
void free_tree(struct bst_node *parent){
  if(!parent){
    return;
  }

  // postorder traversal
  free_tree(parent->left);
  free_tree(parent->right);

  free_list(parent->list);
  free(parent->key);
  free(parent);
}
