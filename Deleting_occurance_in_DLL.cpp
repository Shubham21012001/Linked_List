#include <iostream>
#include<vector>
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


// time comp is O(n) and space comp is O(1).....

node* delete_occurance(node* head,int data){
    if(head==nullptr){
        return head;
    }
    node* prev_node = head->back;
    node* forw_node = head->next;
    node* temp = head;

    while(temp){
        if(temp->data==data){
            if(temp==head) head = head->next;
            prev_node = temp->back;
            forw_node = temp->next;

            if(forw_node) forw_node->back = prev_node;
            if(prev_node) prev_node->next = forw_node;
           

            delete temp;
            temp = forw_node;
        }
        else{
           temp=temp->next; 
        }
    }
    return head;
}



int main(){
    vector<int> arr = {10, 3, 9, 10,10,6,8,4,10};
    node* head = arr_to_doubly_ll(arr);
    head = delete_occurance(head,10);
    print(head);
}