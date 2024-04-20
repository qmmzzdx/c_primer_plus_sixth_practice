#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

typedef struct pair
{
    Trnode *parent;
    Trnode *child;
} Pair;

static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void (*pfun)(Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);
static int all_pets_numbers(const Trnode *root);

void InitializeTree(Tree *ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
    return;
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
    return all_pets_numbers(ptree->root); //获取俱乐部中所有宠物的数量;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *find;
    Trnode *new_node;

    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false;
    }
    if ((find = SeekItem(pi, ptree).child) != NULL)
    {
        Kind *temp;
        Kind *node;
        for (temp = find->item.many_petkinds; temp != NULL; temp = temp->next)
        {
            if (strcmp(pi->many_petkinds->petkind, temp->petkind) == 0)
            {
                break;
            }
        }
        if (temp != NULL) //若temp为NULL则说明用户输入的宠物名字和种类与俱乐部中宠物相重复,故无法添加;
        {
            fprintf(stderr, "Can't add duplicate item!\n");
            return false;
        }
        else
        {
            if ((node = (Kind *)malloc(sizeof(Kind))) == NULL)
            {
                fprintf(stderr, "Memory allocation failed!\n");
                return false;
            }
            else
            {
                strcpy(node->petkind, pi->many_petkinds->petkind);
                node->next = NULL;
                for (temp = find->item.many_petkinds; temp->next != NULL; temp = temp->next)
                {
                    continue;
                }
                temp->next = node;
                find->item.pets_count++;
                return true;
            }
        }
    }
    new_node = MakeNode(pi);
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node.\n");
        return false;
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

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;
    look = SeekItem(pi, ptree);

    if (look.child == NULL)
    {
        return false;
    }
    if (look.child->item.pets_count != 1) //结点中有多个同名不同类的宠物;
    {
        //↓使用链表顺序遍历找到符合用户输入的宠物;
        Kind *prior;
        Kind *current;
        for (prior = current = look.child->item.many_petkinds; current != NULL; current = current->next)
        {
            if (strcmp(current->petkind, pi->many_petkinds->petkind) == 0)
            {
                break;
            }
            prior = current;
        }
        if (current != NULL) //找到用户输入种类的宠物;
        {
            prior->next = current->next;
            free(current);
            look.child->item.pets_count--;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //↓若用户输入的宠物只有一种且俱乐部中存在此种宠物则删除整个结点;
        if (0 == strcmp(look.child->item.many_petkinds->petkind, pi->many_petkinds->petkind))
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
            return true;
        }
        else //若用户输入的宠物种类不存在则返回false;
        {
            return false;
        }
    }
}

void Traverse(const Tree *ptree, void (*pfun)(Item item))
{
    if (ptree != NULL)
    {
        InOrder(ptree->root, pfun);
    }
    return;
}

void DeleteAll(Tree *ptree)
{
    if (ptree != NULL)
    {
        DeleteAllNodes(ptree->root);
    }
    ptree->root = NULL;
    ptree->size = 0;
    return;
}

static void InOrder(const Trnode *root, void (*pfun)(Item item))
{
    if (root != NULL)
    {
        InOrder(root->left, pfun);
        (*pfun)(root->item);
        InOrder(root->right, pfun);
    }
    return;
}

static void DeleteAllNodes(Trnode *root)
{
    Trnode *pright;

    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        Kind *temp;
        while (root->item.many_petkinds != NULL)
        {
            temp = root->item.many_petkinds->next;
            free(root->item.many_petkinds);
            root->item.many_petkinds = temp;
        }
        free(root);
        DeleteAllNodes(pright);
    }
    return;
}

static void AddNode(Trnode *new_node, Trnode *root)
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
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
    return;
}

static bool ToLeft(const Item *i1, const Item *i2)
{
    return strcmp(i1->petname, i2->petname) < 0 ? true : false;
}

static bool ToRight(const Item *i1, const Item *i2)
{
    return strcmp(i1->petname, i2->petname) > 0 ? true : false;
}

static Trnode *MakeNode(const Item *pi)
{
    Kind *temp;
    Trnode *new_node;

    if ((new_node = (Trnode *)malloc(sizeof(Trnode))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    if ((temp = (Kind *)malloc(sizeof(Kind))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->item.petname, pi->petname);
    strcpy(temp->petkind, pi->many_petkinds->petkind);
    temp->next = NULL;
    new_node->item.many_petkinds = temp;
    new_node->item.pets_count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
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

static void DeleteNode(Trnode **ptr)
{
    Kind *tp;
    Trnode *temp;

    if ((*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
    }
    else if ((*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
    }
    else
    {
        for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
        {
            continue;
        }
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr = (*ptr)->left;
    }
    while (temp->item.many_petkinds != NULL)
    {
        tp = temp->item.many_petkinds->next;
        free(temp->item.many_petkinds);
        temp->item.many_petkinds = tp;
    }
    free(temp);
    return;
}

static int all_pets_numbers(const Trnode *root)
{
    static int count = 0;

    if (root != NULL)
    {
        all_pets_numbers(root->left);
        count += root->item.pets_count; //使用递归累加所有结点中的同名不同类的宠物数量;
        all_pets_numbers(root->right);
    }
    return count;
}
