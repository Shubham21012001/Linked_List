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

node *deletion_head(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

node *deletion_tail(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    node *temp = head;
    node *last;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
        last = temp->next;
    }
    temp->next = nullptr;
    last->back = nullptr;
    delete last;
    return head;
}

node *deletion_position(node *head, int position)
{
    if (head == nullptr)
        return nullptr;

    node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        if (count == position)
        {
            break;
        }
        temp = temp->next;
    }
    if (position > count)
    {
        return nullptr;
    }
    node *prev = temp->back;
    node *front = temp->next;

    if (prev == nullptr && front == nullptr)
        return nullptr;
    else if (prev == nullptr)
        return deletion_head(head);
    else if (front == nullptr)
        return deletion_tail(head);

    prev->next = front;
    front->back = prev;
    temp->back = temp->next = nullptr;
    delete temp;
    return head;
}

node *deletion_element(node *head, int element)
{
    if (head == nullptr)
        return nullptr;

    node *temp = head;
    while (temp)
    {
        if (temp->data == element)
        {
            break;
        }
        temp = temp->next;
    }
    node *prev = temp->back;
    node *front = temp->next;

    if (prev == nullptr && front == nullptr)
        return nullptr;
    else if (prev == nullptr)
        return deletion_head(head);
    else if (front == nullptr)
        return deletion_tail(head);

    prev->next = front;
    front->back = prev;
    temp->back = temp->next = nullptr;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {6, 3, 9, 10};
    node *head = arr_to_doubly_ll(arr);
    // head = deletion_head(head);
    // head = deletion_tail(head);
    // head = deletion_position(head, 4);
    // head = deletion_element(head, 10);
    print(head);
}