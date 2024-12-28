

// Sorting Linked List, nodes having data 0,1,2.......

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

// Time complexity of this code is O(2n) , (not optimal)

// node *sorting(node *head)
// {
//     int zero = 0, one = 0, two = 0;
//     node *temp = head;
//     while (temp)
//     {
//         if (temp->data == 0)
//             zero++;
//         if (temp->data == 1)
//             one++;
//         if (temp->data == 2)
//             two++;
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp)
//     {
//         if (zero != 0)
//         {
//             temp->data = 0;
//             zero--;
//         }
//        else if (one != 0)
//         {
//             temp->data = 1;
//             one--;
//         }
//        else if (two != 0)
//         {
//             temp->data = 2;
//             two--;
//         }
//         temp = temp->next;
//     }
//     return head;
// }


// Time Complexity of this code is O(n) and Space complexity is O(1)..... (Optimal Solution)

node *sorting(node *head)
{
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node *temp = head;
    node *one = new node(-1);
    node* one_head = one;
    node *two = new node(-1);
    node* two_head = two;
    node *zero = new node(-1);
    node* zero_head = zero;


    while (temp!=nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else if (temp->data == 2)
        {
            two->next = temp;
            two = two->next;
        }
        temp=temp->next;
    }
     zero->next = (one_head->next)? one_head->next:two_head->next;
     one->next = two_head->next;
     two->next = nullptr;
     return zero_head->next;
}

int main()
{
    node *head2 = new node(2);
    head2->next = new node(1);
    head2->next->next = new node(2);
    head2->next->next->next = new node(0);
    head2->next->next->next->next = new node(1);
    head2->next->next->next->next->next = new node(0);
    head2->next->next->next->next->next->next = new node(1);

    node *head = sorting(head2);
    print(head);
}