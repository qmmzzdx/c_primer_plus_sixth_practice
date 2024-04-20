#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>
#define TSIZE 45

struct film
{
    char title[TSIZE];
    int rating;
};

typedef struct film Item;

#define MAXSIZE 100
typedef struct list
{
    Item entries[MAXSIZE];
    int items;
} List;

void InitializeList(List *plist);

bool ListIsEmpty(const List *plist);

bool ListIsFull(const List *plist);

unsigned int ListItemCount(const List *plist);

bool AddItem(Item item, List *plist);

void Traverse(const List *plist, void (*pfun)(Item item));

void EmptyTheList(List *plist);

#endif
