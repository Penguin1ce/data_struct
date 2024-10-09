#include <iostream>
using namespace std;
class chainNode
{
public:
    int data;
    chainNode *Next;
};
chainNode *initList()
{
    chainNode *list = new chainNode;
    list->Next = NULL;
    list->data = 0;
    return list;
}
void headInsert(chainNode *head, int data)
{
    chainNode *newNode = new chainNode;
    newNode->data = data;
    newNode->Next = head->Next;
    head->Next = newNode;
    head->data++;
}
void tailInsert(chainNode *tail, int data)
{
    chainNode *head = tail;
    chainNode *newNode = new chainNode;
    newNode->data = data;
    newNode->Next = NULL;
    while (tail->Next != NULL)
    {
        tail = tail->Next;
    }
    tail->Next = newNode;
    head->data++;
}
void deleteList(chainNode *head, int data)
{
    chainNode *p = head;
    while (p->Next != NULL)
    {
        if (p->Next->data == data)
        {
            chainNode *temp = p->Next;
            p->Next = p->Next->Next;
            delete temp;
            head->data--;
        }
        else
        {
            p = p->Next;
        }
    }
}
void printlist(chainNode *head)
{
    chainNode *p = head->Next;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->Next;
    }
    cout << endl;
}
int main()
{
    chainNode *list=initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    tailInsert(list, 6);
    printlist(list);
    deleteList(list, 3);
    printlist(list);
    deleteList(list,1);
    printlist(list);
    return 0;
}
