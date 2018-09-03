#ifndef BST_H
#define BST_H

struct bst_node {
  struct bst_node *equal;
  struct bst_node *left;
  struct bst_node *right;
  char *key;
  struct entry *data;
};

struct result_t {
  struct entry* data;
  int comp_count;
};

struct bst_node* makedict();
struct bst_node* insert(struct bst_node* parent, struct entry* data);

#endif
