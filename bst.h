#ifndef BST_H
#define BST_H

struct bst_node {
  struct bst_node *left;
  struct bst_node *right;
  struct bst_node *equal;
  char *key;
  struct record *record;
};

struct bst_node * insert(struct bst_node *parent, struct record *record);
void search(struct bst_node *parent, char *key, FILE *file);
void free_tree(struct bst_node *parent);

#endif
