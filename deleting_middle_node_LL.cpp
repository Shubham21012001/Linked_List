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

node *print(node *head)
{
    cout << "Provided Linked List : ";
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}


// FIXME: time comp is O(n) and space comp O(1)
// using tortoise and hair algorithm and counting slow pointer ...


// node *middle(node *head)
// {
//     int count = 0;
//     if(head==nullptr) return head;
//     node *slow = head;
//     node *fast = head;

//     while (fast != nullptr && fast->next != nullptr)
//     {
//         slow = slow->next;
//         count++;
//         fast = fast->next->next;
//     }
//     slow = head;
//     while (count != 1)
//     {
//         slow = slow->next;
//         count--;
//     }
//     slow->next=slow->next->next;
//     return head;
// }



// TODO: time comp is O(n/2) and space comp is O (1) (optimal solution)

node *middle(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    node *slow = head;
    node *fast = head;
    fast = fast->next->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *middle = slow->next;
    slow->next = slow->next->next;
    delete middle;
    return head;
}


int main()
{
    node *head2 = new node(7);
    head2->next = new node(12);
    head2->next->next = new node(3);
    head2->next->next->next = new node(10);
    head2->next->next->next->next = new node(0);

    node *head = middle(head2);
    print(head);
}