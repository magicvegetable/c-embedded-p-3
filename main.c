#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ullint;

typedef struct List {
  char *name;
  ullint price;
  ullint pages_amount;
  ullint weight;
  ullint publication_year;
  struct List *next;
} List;

void List_print(List *top) {
  while (top != NULL) {
    printf("\nname = %s\n", top->name);
    printf("\tprice = %llu$\n", top->price);
    printf("\tpages amount = %llu\n", top->pages_amount);
    printf("\tweight = %llu g\n", top->weight);
    printf("\tpublication year = %llu\n", top->publication_year);
    top = top->next;
  }
}

List *List_push_forward(List *top,
                        char *name,
                        ullint price,
                        ullint pages_amount,
                        ullint weight,
                        ullint publication_year) {
  List *node = (List *)malloc(sizeof(List));
  node->name = name;
  node->price = price;
  node->pages_amount = pages_amount;
  node->weight = weight;
  node->publication_year = publication_year;
  node->next = top;
  return node;
}

void List_free(List *top) {
  while (top != NULL) {
    List *node = top;
    top = top->next;
    free(node);
  }
}

int main() {
  List *list = NULL;
  list = List_push_forward(list, "Harry Potter and the Philosopher's Stone", 20, 223, 500, 1997);
  list = List_push_forward(list, "Harry Potter and the Chamber of Secrets", 22, 251, 550, 1998);
  list = List_push_forward(list, "Harry Potter and the Prisoner of Azkaban", 24, 317, 600, 1999);
  list = List_push_forward(list, "Harry Potter and the Goblet of Fire", 28, 636, 900, 2000);
  list = List_push_forward(list, "Harry Potter and the Order of the Phoenix", 30, 766, 1000, 2003);
  list = List_push_forward(list, "Harry Potter and the Half-Blood Prince", 26, 607, 950, 2005);
  list = List_push_forward(list, "Harry Potter and the Deathly Hallows", 32, 607, 1000, 2007);

  List_print(list);
  List_free(list);
}
