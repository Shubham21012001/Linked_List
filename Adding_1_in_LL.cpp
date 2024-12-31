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

// FIXME: here is the iterative solution having time complexity is : O(3n) and space complexity is : O(1) (not optimal)

// node *reverse_LL(node *head)
// {
//     if (head == nullptr || head->next == nullptr)
//         return head;
//     node *new_head = reverse_LL(head->next);
//     node *front = head->next;
//     front->next = head;
//     head->next = NULL;
//     return new_head;
// }

// node* Adding_1_in_LL(node* head){
//     head=reverse_LL(head);
//     node* temp = head;
//     int carry=1;
//     while(temp!=nullptr){
//         temp->data=temp->data+carry;
//         if(temp->data<10){
//             carry=0;
//             break;
//         }
//         else { temp->data=0;} // temp->data should not be 10 it should be 0 . (1 in the carry)
//         temp=temp->next;
//     }
//      if(carry==1){
//         node* new_node = new node(1);
//         head=reverse_LL(head);
//         new_node->next = head;
//         head=new_node;
//         return head;
//      }
//     head = reverse_LL(head);
//     return head;
// }



// TODO: here is recursive code having time comp. O(n) but space comp. is O(n) ....

int Add_helper(node *temp)
{
    if (temp == nullptr)
        return 1;

    int carry = Add_helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}

node* Adding_1_in_LL(node* head){
    int carry = Add_helper(head);
    if(carry==1){
        node* new_node=new node(1);
        new_node->next = head;
        head = new_node;
    }
     return head;
}
int main()
{
    node *head2 = new node(9);
    head2->next = new node(9);
    head2->next->next = new node(9);
    head2->next->next->next = new node(9);
    head2->next->next->next->next = new node(9);

    node *head = Adding_1_in_LL(head2);
    print(head);
}