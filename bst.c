#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entry.h"
#include "bst.h"

struct bst_node* makedict(){
 return NULL;
}

/**
 * Inserts a new node into the right position
 * @param a pointer to a parent node, a key (name) and a pointer to the data
 * @return the bst with a new child inserted
 */
struct bst_node* insert(struct bst_node* parent, struct entry* data){
  char *key = data->name;
  struct bst_node **insert_location = &parent;

  // find the right insertion point
  while(*insert_location){
    if(strcmp(key, (*insert_location)->key) == 0){
      insert_location = &((*insert_location)->equal);
    } else if (strcmp(key, (*insert_location)->key) < 0) {
      insert_location = &((*insert_location)->left);
    } else {
      insert_location = &((*insert_location)->right);
    }
  }

  // allocate memory for new node
  *insert_location = (struct bst_node*) malloc(sizeof(struct bst_node));

  // inserts new node
  (*insert_location)->equal = NULL;
  (*insert_location)->left = NULL;
  (*insert_location)->right = NULL;

  (*insert_location)->key = (char *) malloc(strlen(key) * sizeof(char) + 1);
  strcpy((*insert_location)->key, key);

  (*insert_location)->data = data;

  return parent;
}

// result search(bst_node* parent, char key){
//   int comp;
//   int comp_count;
//   result_t result;
//   bst **curr_location = &parent;
//
//   while(*curr_location){
//     if(!curr_location){
//       return NULL;
//     }
//
//     comp = strcmp(key, (*curr_location)->key);
//     comp_count++;
//
//     if(comp == 0){
//       result.data = curr_location->data;
//       result.comp_count = comp_count;
//     } else if(cmp < 0){
//       curr_location = &((*curr_location)->left);
//     } else {
//       curr_location = &((*curr_location)->right);
//     }
//   }
//
//   return result;
// }

void free_tree(struct bst_node* parent){
  if(!parent){
    return;
  }
  free_tree(parent->left);
  free_tree(parent->right);
  free(parent);
}
