#include <iostream>
#include <stack>
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

// FIXME: time comp. is O(2n) and space comp. is O(n) (not optimal sol.)

// node *palindrome_LL(node *head)
// {
//     if (head == nullptr)
//     {
//         cout << "No element";
//         return head;
//     }

//     node *temp = head;
//     stack<int> st;
//     while (temp)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp)
//     {
//         if (temp->data == st.top())
//         {
//             temp = temp->next;
//             st.pop();
//         }
//         else
//         {
//             cout << "Not a palindrome" << endl;
//             return head;
//         }
//     }
//     cout << "It is a palindrome" << endl;
//     return head;
// }

// TODO: here is the optimal solution having time comp. O(2n) and space comp. O(1)
// (best solution)

node *reverse_LL(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    node *new_head = reverse_LL(head->next);
    node *front = head->next;
    front->next = head;
    head->next = NULL;
    return new_head;
}

node *palindrome_LL(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "True" << endl;
        return head;
    }
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *new_head = reverse_LL(slow->next);
    node *first = head;
    node *second = new_head;
    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse_LL(new_head);
            cout << "False" << endl;
            return head;
        }
        first = first->next;
        second = second->next;
    }
    reverse_LL(new_head);
    cout << "True" << endl;
    return head;
}

int main()
{
    node *head2 = new node(7);
    head2->next = new node(3);
    head2->next->next = new node(0);
    head2->next->next->next = new node(1);
    head2->next->next->next->next = new node(0);
    head2->next->next->next->next->next = new node(3);
    head2->next->next->next->next->next->next = new node(7);

    node *head = palindrome_LL(head2);
    print(head);
}