#ifndef LLIST_H
#define LLIST_H

struct llist {
  struct node *head;
  struct node *foot;
};

struct node {
  struct record *record;
  struct node *next;
};

struct llist *make_list();
struct llist *insert_list(struct llist *list, struct record *record);
void free_list(struct llist *list);

#endif
