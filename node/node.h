// node.h - linked list implementation

#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>

#define FMT "%d "

typedef int Item;

typedef struct s_node {
   Item item;
   struct s_node *next;
} *List;

List new_node(Item x, List p);
void display(List L);
void append(List *A, List B);
void destroy_list(List *L);
int list_size(List L);
int contains(Item x, List L);
Item get_last(List L);
List clone(List L);
List reverse(List L);
void display_reverse(List L);
void insert(Item x, List L);
List replace(Item a, Item b, List L);

#endif
