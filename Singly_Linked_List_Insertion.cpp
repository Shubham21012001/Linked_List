#include <bits/stdc++.h>

#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};
node *arr_to_ll(vector<int> arr)
{ // converting array to linked list
    node *head = new node(arr[0], nullptr);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

node *print(node *head)
{ // traversing and printing data of nodes
    int count = 0;
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        count++;
        temp = temp->next;
    }
    cout << endl;
    cout << "Length : "<<count;
}
node* insertion_head(node*head,int value){
    node* temp=new node(value,head);
    return temp;
}
node* insertion_last(node*head,int value){
    node* temp= new node(value,nullptr);
    if(head==nullptr) return temp;
    node*start=head;
    while(head){
        head=head->next;
        if(head->next==nullptr){
            head->next=temp;
            break;
        } }
    return start;
}

node* insertion_position(node* head,int value,int position){
    node* temp=new node(value,nullptr);
    if(head==nullptr) return temp;
    if(position==1){
        temp->next=head;
        return temp;
    }
     node* start=head;
     int count=1;
     while(head){
        count++;
        if(count==position){
            temp->next=head->next;
            head->next=temp;
            return start;  
        }
         head=head->next;
    }
     return start;
}

 node* insertion_element(node* head,int value,int element){
    node* temp=new node(value,nullptr);
    if(head==nullptr) return temp;
    if(head->data==element){
        temp->next=head;
        return temp;
    }
     node* start=head;
    while(head){
        if(head->next->data==element){
            temp->next=head->next;
            head->next=temp;
            return start;  
        }
        head=head->next;
    }
     return start;
}
int main()
{
    vector<int> arr = {8, 2, 3, 4};
    node *head = arr_to_ll(arr);
    // head=insertion_head(head,10);
    // head=insertion_last(head,10);
    // head=insertion_position(head,20,3);
    // head=insertion_element(head,20,4);
    print(head);
}