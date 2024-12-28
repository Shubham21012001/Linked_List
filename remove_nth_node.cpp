#include <iostream>
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

node *print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

// FIXME: Here the time complexity is O(2n) na dspace comp. is O(1)... (not optimal code)

// node *removing_node(node *head, int n)
// {
//     if (head == nullptr)
//     {
//         return nullptr;
//     }
//     node *temp = head;
//     int count = 0;
//     while (temp)
//     {
//         count++;
//         temp = temp->next;
//     }

//     if (n > count)
//     {
//         return head;
//     }
//     temp = head;
//     if (n == count)
//     {
//         head = head->next;
//         delete temp;
//         return head;
//     }

//     int stop = count - n - 1; // here -1 is done bcz when count will be 4 , temp will at its 5th position.
//     count = 0;
//     while (count != stop)
//     {
//         count++;
//         temp = temp->next;
//     }
//     node *bye_node = temp->next;
//     temp->next = temp->next->next;
//     delete bye_node;
//     return head;
// }

// TODO: here is the optimal solution , time comp. O(n) and space comp. O(1)


node *removing_node(node *head, int n)
{
    node *fast = head;
    node *slow = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        return head->next;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    node *bye_node = slow->next;
    slow->next = slow->next->next;
    delete bye_node;
    return head;
}

int main()
{
    node *head2 = new node(7);
    head2->next = new node(3);
    head2->next->next = new node(0);
    head2->next->next->next = new node(1);
    head2->next->next->next->next = new node(5);
    head2->next->next->next->next->next = new node(6);
    head2->next->next->next->next->next->next = new node(2);

    node *head = removing_node(head2, 7);
    print(head);
}