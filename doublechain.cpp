#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *pre;
    Node *next;
};
Node *initList()
{
    Node *L = new Node;
    L->data = 0;
    L->next = NULL;
    L->pre = NULL;
    return L;
}
void headInsert(Node *L, int data)
{
    Node *head = new Node;
    head->data = data;
    if (L->data == 0)
    {
        // 此时链表为空
        head->next = L->next;
        head->pre = L;
        L->next = head;
    }
    else
    {
        head->pre = L;
        head->next = L->next;
        L->next->pre = head;
        L->next = head;
    }
    L->data++;
}
void tailInsert(Node *L, int data)
{
    Node *node = L;
    Node *n = new Node;
    n->data = data;
    while (node->next != NULL)
    {
        node = node->next;
    }
    n->next = node->next;
    node->next = n;
    n->pre = node;
    L->data++;
}
void printList(Node *L)
{
    Node *node = L->next;
    while (node)
    {
        cout << node->data << endl;
        node = node->next;
    }
    cout << "NULL" << endl;
}
int deleteList(Node *L, int data)
{
    Node *node = L->next;
    while (node != NULL)
    {
        if (node->data == data)
        {
            node->pre->next = node->next;
            if (node->next != NULL)
            {
                node->next->pre = node->pre;
            }
            L->data--;
            delete node;
            return true;
        }
        node = node->next;
    }
    return false;
}
int main()
{
    Node *l = initList();
    headInsert(l, 1);
    headInsert(l, 2);
    headInsert(l, 3);
    headInsert(l, 4);
    headInsert(l, 5);
    headInsert(l, 6);
    headInsert(l, 7);
    headInsert(l, 8);
    tailInsert(l, 10);
    tailInsert(l,10);
    printList(l);
    deleteList(l, 10);
    printList(l);
    return 0;
}