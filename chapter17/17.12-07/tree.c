#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

typedef struct pair
{
    Node *parent;
    Node *child;
} Pair;

static Node *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Node *new_node, Node *root);
static void InOrder(const Node *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node *ptr);

void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    return NULL == ptree->root;
}

bool TreeIsFull(const Tree *ptree)
{
    return MAXITEMS == ptree->size;
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Node *new_node;
    Pair seek;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "No memory available!\n");
        return false;
    }
    if ((seek = SeekItem(pi, ptree)).child != NULL)
    {
        seek.child->item.count++;
        return true;
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    ptree->size++;
    if (ptree->root == NULL)
    {
        ptree->root = new_node;
    }
    else
    {
        AddNode(new_node, ptree->root);
    }
    return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

const Item *WhereInTree(const Item *pi, const Tree *ptree)
{
    Node *pn;

    pn = SeekItem(pi, ptree).child;
    return NULL == pn ? NULL : &(pn->item);
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);

    if (look.child == NULL)
    {
        return false;
    }
    if (look.child->item.count > 0)
    {
        look.child->item.count--;
    }
    else
    {
        if (look.parent == NULL)
        {
            DeleteNode(&ptree->root);
        }
        else if (look.parent->left == look.child)
        {
            DeleteNode(&look.parent->left);
        }
        else
        {
            DeleteNode(&look.parent->right);
        }
        ptree->size--;
    }
    return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
    {
        InOrder(ptree->root, pfun);
    }
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
    {
        DeleteAllNodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
}

static void InOrder(const Node *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
}

static void DeleteAllNodes(Node *root)
{
    Node *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode(Node *new_node, Node *root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL)
        {
            root->left = new_node;
        }
        else
        {
            AddNode(new_node, root->left);
        }
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
        {
            root->right = new_node;
        }
        else
        {
            AddNode(new_node, root->right);
        }
    }
    else
    {
        fprintf(stderr, "Can't add repetitive item!\n");
        exit(EXIT_FAILURE);
    }
    return;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    return strcmp(i1->wrd, i2->wrd) < 0;
}

static bool ToRight(const Item *i1, const Item *i2)
{
    return strcmp(i1->wrd, i2->wrd) > 0;
}

static Node *MakeNode(const Item *pi)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    if (new_node != NULL)
    {
        new_node->item = *pi;
        new_node->item.count = 1;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL)
    {
        return look;
    }
    while (look.child != NULL)
    {
        if (ToLeft(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, &(look.child->item)))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
        {
            break;
        }
    }
    return look;
}

static void DeleteNode(Node **ptr)
{
    Node *temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {
        temp = (*ptr)->left;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    return;
}
