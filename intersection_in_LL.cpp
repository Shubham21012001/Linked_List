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



// FIXME: time comp is O(N+M)logN and space comp is O(N).

// node *intersection(node *head1,node* head2)
// {
//     map<node*,int> mpp; // decleration of map
//     node *temp = head1;
//     while (temp != NULL)
//     {
//         mpp[temp] = 1;
//         temp = temp->next;
//     }
//      temp=head2;
//      while(temp!=NULL){
//         if(mpp.find(temp)!=mpp.end())  // NOTE
//         return temp;
//         temp=temp->next;
//      }
//      return nullptr;
// }




// FIXME: Time comp is O(n+m) and space comp is O(1).

// node* intersection(node* head1,node* head2){
//     node* temp1=head1;
//     node* temp2=head2;
//     int count1=0,count2=0,diff=0;
//     while(temp1){
//         count1++;
//         temp1=temp1->next;
//     }
//     while(temp2){
//         count2++;
//         temp2=temp2->next;
//     }
//     temp1=head1;
//     temp2=head2;

//     if(count1>count2){
//         diff=count1-count2;
//         while(diff!=0){
//             temp1=temp1->next;
//             diff--;
//         }
//     }
//     if(count1<count2){
//         diff=count2-count1;
//         while(diff!=0){
//             temp2=temp2->next;
//             diff--;
//         }
//     }

//     while(temp1!=nullptr && temp2!=nullptr){
//         if(temp1==temp2){
//             return temp1;
//         }
//         temp1=temp1->next;
//         temp2=temp2->next;
//     }
//     return nullptr;
// }




// TODO: time comp is O(N+M) and O(1) (Optimal Solution)....

node *intersection(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
            return temp1;

        if (temp1 == nullptr)
            temp1 = head2;
        if (temp2 == nullptr)
            temp2 = head1;
    }
    return temp1;
}



int main()
{
    node *head1 = new node(7);
    head1->next = new node(3);
    head1->next->next = new node(1000);
    head1->next->next->next = new node(1);
    head1->next->next->next->next = new node(0);

    node *head2 = new node(9);
    head2->next = new node(2);
    head2->next->next = head1->next->next;

    node *head = intersection(head1, head2);
    if (head)
    {
        cout << "Intersection exists : " << head->data;
    }
    else
    {
        cout << "Intersection not exists";
    }
}