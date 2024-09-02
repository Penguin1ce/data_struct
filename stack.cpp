#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *initstack()
{
    Node *S = new Node;
    S->data = 0;
    S->next = NULL;
    return S;
}
int isEmpty(Node *s)
{
    if (s->data == 0 || s->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getTop(Node *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    else
    {
        return s->next->data;
    }
}
void push(Node *s, int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = s->next;
    s->next = node;
    s->data++;
}
void printfStack(Node *s)
{
    Node *node = s->next;
    while (node)
    {
        cout << "node= " << node->data << endl;
        node = node->next;
    }
    cout << "NULL" << endl;
}
int pop(Node *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    else
    {
        Node *node = s->next;
        int data = node->data;
        s->next = node->next;
        delete node;
        s->data--;
        return data;
    }
}
int main()
{
    Node *s = initstack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    printfStack(s);
    pop(s);
    printfStack(s);
    return 0;
}