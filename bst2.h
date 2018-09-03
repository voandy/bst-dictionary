#ifndef BST2_H
#define BST2_H

struct bst_node {
  struct bst_node *left;
  struct bst_node *right;
  char *key;
  struct llist *list;
};

struct bst_node * insert(struct bst_node *parent, struct record *record);
void search(struct bst_node *parent, char *key, FILE *file);
void free_tree(struct bst_node *parent);

#endif
