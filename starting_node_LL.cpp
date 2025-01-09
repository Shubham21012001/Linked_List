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
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;
}

// FIXME: Time complexity is O(nlogn) and space complexity is O(n)....

// node *starting_node(node *head)
// {
//     node *temp = head;
//     map<node *, int> mpp;
//     while (temp != nullptr)
//     {
//         if (mpp.find(temp) != mpp.end())
//             return temp;
//         mpp[temp] = 1;
//         temp = temp->next;
//     }
//     return head;
// }


// TODO: Time comp is O(n) and the space comp is O(1).... 

node *starting_node(node *head)
{
    node *slow = head;
    node *fast = head;
    int n = 0;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return head;
}

int main()
{
    node *head = new node(3);
    head->next = new node(4);
    head->next->next = new node(6);
    head->next->next->next = new node(9);
    head->next->next->next->next = new node(2);
    head->next->next->next->next->next = new node(10);
    head->next->next->next->next->next->next = head->next->next;

    node *head1 = starting_node(head);
    cout << head1->data;
}