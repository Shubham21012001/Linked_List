#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};

node *arr_to_ll(vector<int> arr)
{
    node *head = new node(arr[0], nullptr);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

node *print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
// Iterative way of reversing a linked list

node *reverse_ll(node *head)
{

    if (head == nullptr)
    {
        return nullptr;
    }

    node *prev = NULL;
    node *current = head;
    node *nxt = nullptr;

    while (current != nullptr)
    {
        nxt = current->next;
        current->next = prev;

        prev = current;
        current = nxt;
    }

    return prev;
}

int main()
{
    vector<int> arr = {8, 2, 3, 4};
    node *head = arr_to_ll(arr);
    head = reverse_ll(head);
    print(head);
}