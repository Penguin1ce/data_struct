#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *pre;
    Node *Next;
};
Node *initList()
{
    Node *list = new Node;
    list->data = 0;
    list->pre = list;
    list->Next = list;
    return list;
}
void headInsert(Node *L, int data)
{
    Node *head = new Node;
    head->data = data;
    head->Next = L->Next;
    head->pre = L;
    head->Next->pre = head;
    L->Next = head;
    L->data++;
}
void tailInsert(Node *L, int data)
{
    Node *aim = L->Next;
    Node *newNode = new Node;
    newNode->data = data;
    while (aim->Next != L)
    {
        aim = aim->Next;
    }
    newNode->pre = aim;
    newNode->Next = L;
    aim->Next = newNode;
    L->pre = newNode;
    L->data++;
}
int deleteList(Node *L, int data)
{
    Node *aim = L->Next;
    while (aim != L)
    {
        if (aim->data == data)
        {
            aim->Next->pre = aim->pre;
            aim->pre->Next = aim->Next;
            L->data--;
            delete aim;
            return true;
        }
        else
        {
            aim = aim->Next;
        }
    }
    return false;
}
void printList(Node *L)
{
    Node *node = L->Next;
    while (node != L)
    {
        cout << node->data << endl;
        node = node->Next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Node *L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    printList(L);
    deleteList(L, 2);
    printList(L);
    tailInsert(L, 5);
    printList(L);
    cout << L->data << endl;
    return 0;
}