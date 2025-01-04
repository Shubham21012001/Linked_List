#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;

public:
    node(int data1, node *next1=nullptr)
    {
        data = data1;
        next = next1;
    }
};

node* print(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    return head;
}


//FIXME: We are using hashing , time comp is O(nlogn) and space comp is O(n)

// node* detect_loop(node* head){
//     map<node*,int>mpp;
//     node* temp = head;
//     while(temp!=nullptr){
//         if(mpp.find(temp)!=mpp.end()) {
//             cout<<"True";
//             return head;
//         }
//         mpp[temp]=1;
//         temp=temp->next;
//     }
//     cout<<"False";
//     return head;
//     }



//TODO: We are using tortoise & hair meathod , time comp is O(n) and space comp is O(1)

node* detect_loop(node* head){
    if(head==nullptr || head->next==nullptr){
        cout<<"FALSE";
        return head;
    }
    node* slow=head;
    node* fast=head;
    
    while(fast==nullptr||fast->next==nullptr){

        if(slow==fast){
            cout<<"TRUE";
            return slow;
        }
        slow=slow->next;
        fast=fast->next->next; 
    }
    cout<<"FALSE";
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

    detect_loop(head);

}
