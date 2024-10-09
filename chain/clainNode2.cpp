#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *initList()
{
    Node *list = new Node;
    list->next = list;
    list->data = 0;
    return list;
}
void headInsert(Node *list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = list->next;
    list->next = newNode;
    list->data++;
}
void backInsert(Node *list, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    Node *node = list->next;
    while (node->next != list)
    {
        node = node->next;
    }
    node->next = newNode;
    newNode->next = list;
    list->data++;
}
int deleteL(Node *L, int data)
{
    Node *aim = L->next;
    Node *preNode = L;
    while (aim != L)
    {
        if (aim->data == data)
        {
            // 删除操作
            preNode->next = aim->next;
            delete aim;
            L->data--;
            return true;
        }
        preNode = aim;
        aim = aim->next;
    }
    return false;
}
void printList(Node *list)
{
    Node *node = list->next;
    while (node != list)
    {
        cout << node->data << endl;
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    printList(list);
    backInsert(list, 6);
    printList(list);
    deleteL(list, 1);
    printList(list);
    
    return 0;
}