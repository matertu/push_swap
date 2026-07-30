#include "node.h"

List new_node(Item x, List p) {
   List n = malloc(sizeof(struct s_node));
   n->item = x;
   n->next = p;
   return n;
} 

void append(List *A, List B) {
   if( B == NULL ) return;
   while( *A != NULL ) A = &(*A)->next;
   *A = B;
}

void destroy_list(List *L) {
   while( *L != NULL ) {
      List n = *L;
      *L = n->next;
      free(n);
   }
}

int list_size(List L) {
   if( L == NULL ) return 0;
   return 1 + list_size(L->next);
}

int contains(Item x, List L) {
   if( L == NULL ) return 0;
   if( x == L->item ) return 1;    
   return contains(x, L->next);
}

Item get_last(List L) {
   if (L == NULL) abort();
   if (L->next == NULL) return L->item;
   return get_last(L->next);
}

List reverse(List L) {
   if (L) return reverse(L->next);
   return NULL;
}

void insert(Item x, List L) {
   if(!L) abort();
   while(L->item < x)
      L = L->next;
   L->next = new_node(x, L->next);
}

