#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void InitializeList(List *plist)
{
    plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
    return 0 == plist->items;
}

bool ListIsFull(const List *plist)
{
    return MAXSIZE == plist->items;
}

unsigned int ListItemCount(const List *plist)
{
    return plist->items;
}

bool AddItem(Item item, List *plist)
{
    if (plist->items == MAXSIZE)
    {
        return false;
    }
    plist->entries[plist->items++] = item;
    return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
    int i;

    for (i = 0; i < plist->items; i++)
    {
        (*pfun)(plist->entries[i]); //使pun指向的函数作用于项目数组中的每一项;
    }
}

void EmptyTheList(List *plist)
{
    plist->items = 0;
}
