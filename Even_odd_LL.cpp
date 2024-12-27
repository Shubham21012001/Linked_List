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


// This i tried myself but its not optimal solution , space comp. is o(n) and time comp is o(n)......
 // ( LOT OF VARIABLES )

//   node* odd_even_LL(node* head){
//     node* temp = head;

//     node* current_odd = new node(-1);
//     node* odd = current_odd;
//     node* current_even = new node(-1);
//     node* even = current_even;
//     int i=1;

//     while(temp){
//         if(i%2!=0){
//            node* new_node = new node(temp->data);
//            current_odd->next = new_node;
//            current_odd=current_odd->next;
//         }
//         else{
//             node* new_node = new node(temp->data);
//             current_even->next = new_node;
//             current_even=current_even->next;
//         }
//         temp=temp->next;
//         i++;
//     }
//      current_odd->next = even->next;
//      return odd->next;
//   }




// Lets try it for space complexity O(1).....

node *odd_even_LL(node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    node *odd = head;
    node *even = head->next;
    node *even_head = even;

    while (even!=nullptr && even->next!=nullptr)
    {
        odd->next = odd->next->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }

    odd->next = even_head;
    return head;
}


int main()
{
    node *head2 = new node(2);
    head2->next = new node(3);
    head2->next->next = new node(4);
    head2->next->next->next = new node(5);
    head2->next->next->next->next = new node(6);
    head2->next->next->next->next->next = new node(7);
    head2->next->next->next->next->next->next = new node(9);

    node *head = odd_even_LL(head2);
    print(head);
}