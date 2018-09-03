/* =====================================================================
  Adaped from code written by Alistair Moffat for the book
  "Programming, Problem Solving, and Abstraction with C", Pearson
  Custom Books, Sydney, Australia, 2002; revised edition 2012,
  ISBN 9781486010974.
   ================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include "record.h"
#include "llist.h"

// create an empty list
struct llist *make_list(){
  struct llist *list;
  list = (struct llist*) malloc(sizeof(struct llist));

  list->head = NULL;
  list->foot = NULL;

  return list;
}

// insert new record at foot of given list
struct llist *insert_list(struct llist *list, struct record *record){
  struct node *new;
  new = (struct node*) malloc(sizeof(struct node));

  new->record = record;
  new->next = NULL;

  // the first insertion in new list
  if(list->foot == NULL){
    list->head = new;
    list->foot = new;
  } else {
    list->foot->next = new;
    list->foot = new;
  }

  return list;
}

// free a list
void free_list(struct llist *list){
  struct node *curr = list->head;
  struct node *prev;

  while(curr){
    prev = curr;
    curr = curr->next;
    free_record(prev->record);
    free(prev);
  }

  free(list);
}
