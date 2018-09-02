#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <data.h>
#include <string.h>

typedef struct bst_node {
  struct bst_node *left;
  struct bst_node *right;
  char key[MAX_STR];
  entry_t data;
}bst_node;

typedef struct result_t {
  entry_t* data;
  int comp_count;
}result_t;

/**
 * Inserts a new node into the right position
 * @param a pointer to a parent node, a key (name) and a pointer to the data
 * @return the bst with a new child inserted
 */
int insert(bst_node* parent, char key, entry_t* data){
  int comp_count = 0;
  bst **insert_location = &parent;

  // find the right insertion point
  while(*insert_location){
    comp_count ++;
    if(strcmp(key, (*insert_location)->key) < 0){
      insert_location = &((*insert_location)->left);
    } else {
      insert_location = &((*insert_location)->right);
    }
  }

  // allocate memory for new node
  *insert_location = (bst*) malloc(sizeof(struct bst_node));

  // inserts new node
  (*insert_location)->left = NULL;
  (*insert_location)->right = NULL;
  strcpy((*insert_location)->key, key);
  (*insertLocation)->data = data;

  return comp_count;
}

result search(bst_node* parent, char key){
  int comp;
  int comp_count;
  result_t result;
  bst **curr_location = &parent;

  while(*curr_location){
    if(!curr_location){
      return NULL;
    }

    comp = strcmp(key, (*curr_location)->key);
    comp_count++;

    if(comp == 0){
      result.data = curr_location->data;
      result.comp_count = comp_count;
    } else if(cmp < 0){
      curr_location = &((*curr_location)->left);
    } else {
      curr_location = &((*curr_location)->right);
    }
  }

  return result;
}

void free_tree(struct bst_node* parent){
  if(!parent){
    return;
  }
  free_tree(parent->left);
  free_tree(parent->right);
  free(parent);
}
