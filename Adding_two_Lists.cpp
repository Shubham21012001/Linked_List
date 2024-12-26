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
    cout<<endl;
    return head;
}



node *add_two_Lists(node *head1, node *head2)
{
    int carry = 0;

    if (head1 == nullptr && head2 == nullptr)
    {
        return nullptr;
    }
    node *t1 = head1;
    node *t2 = head2;
    node *dummy = new node(-1);
    node *current = dummy;

    while (t1 != nullptr || t2 != nullptr)
    {
        int sum = carry;
        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;

        node *newnode=new node(sum%10);
        carry=sum/10;

        current->next=newnode;
        current=current->next;

        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
    }

    if(carry){
        node* carry_node = new node(carry);
        current->next = carry_node;
     }
    return dummy->next;
}

int main()
{
    node *head1 = new node(3);
    head1->next = new node(5);

    node *head2 = new node(4);
    head2->next = new node(5);
    head2->next->next = new node(9);
    head2->next->next->next = new node(9);

    node *head = add_two_Lists(head1, head2);
    print(head);
}
