#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *back;

public:
    node(int data1, node *next1, node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};
node *arr_to_doubly_ll(vector<int> arr)
{
    node *head = new node(arr[0], nullptr, nullptr);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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
    return head;
}

node *insertion_head(node *head, int data)
{
    node *temp = new node(data, head, nullptr);
    if (head != nullptr)
    {
        head->back = temp;
    }
    head = temp;
    return head;
}

node *insertion_tail(node *head, int data)
{
    node *temp = new node(data, nullptr, nullptr);
    if (head == nullptr)
    {
        return temp;
    }
    node *start = head;
    while (start->next != nullptr)
    {
        start = start->next;
    }
    start->next = temp;
    temp->back = start;
    return head;
}

node *insertion_position(node *head, int data, int position)
{
    node *temp = new node(data, nullptr, nullptr);
    if (head == nullptr)
    {
        return temp;
    }

    if (position == 0)
    {
        return insertion_head(head, data);
    }

    node *prev = head;
    int count = 0;

    while (prev != nullptr && count < position - 1)
    {
        prev = prev->next;
        count++;
    }

    if (prev == nullptr)
    {
        return head;
    }

    if (prev->next == nullptr)
    {
        return insertion_tail(head, data);
    }

    temp->next = prev->next;
    temp->back = prev;
    if (prev->next != nullptr)
    {
        prev->next->back = temp;
    }
    prev->next = temp;

    return head;
}

node *insertion_element(node *head, int data, int element)
{

    if (head == nullptr)
    {
        return head;
    }

    node *current = head;

    while (current != nullptr && current->data != element)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Element " << element << " not found in the list." << endl;
        return head;
    }

    node *temp = new node(data, current->next, current);
    if (current->next != nullptr)
    {
        current->next->back = temp;
    }
    current->next = temp;

    return head;
}

int main()
{
    vector<int> arr = {6, 3, 9, 10};
    node *head = arr_to_doubly_ll(arr);
    // head = insertion_head(head,4);
    // head = insertion_tail(head, 4);
    // head = insertion_position(head, 14, 4);
    // head = insertion_element(head,20,6);
    print(head);
}