

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data1, node *next1=nullptr)
    {
        data = data1;
        next = next1;
    }
};


node *print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Recursive way of reversing a linked list

node *reverse_LL_recursive(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newnode = reverse_LL_recursive(head->next);
    node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newnode;
}

int main()
{ 
    node* head = new node(5);
    head->next = new node(4);
    head->next->next = new node(2);
    head = reverse_LL_recursive(head);
    print(head);
}