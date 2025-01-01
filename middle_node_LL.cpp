#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int data1, node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

// FIXME: time comp is O(n+n/2) and space comp is O(1)..

// node *middle(node *head)
// {
//     node *temp = head;
//     int count = 0;
//     while (temp)
//     {
//         count++;
//         temp = temp->next;
//     }
//     temp = head;
//     int n = count / 2 + 1;
//     while (n != 1)
//     {
//         temp = temp->next;
//         n--;
//     }
//     return temp;
// }

// TODO: 

node *middle(node *head)
{
    node *slow = head;
    node *fast = head;

    while ( fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
     return slow;
}

int main()
{
    node *head2 = new node(7);
    head2->next = new node(12);
    head2->next->next = new node(3);
    head2->next->next->next = new node(10);
    head2->next->next->next->next = new node(0);
    head2->next->next->next->next->next = new node(8);

    node *head = middle(head2);
    cout << head->data;
}