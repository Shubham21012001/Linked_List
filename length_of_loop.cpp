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

// FIXME: We are using hashing , time comp is O(nlogn) and space comp is O(n)

// node* length_of_loop(node* head){
//     map<node*,int>mpp;
//     node* temp = head;
//     int count=0;
//     while(temp!=nullptr){
//         count++;
//         if(mpp.find(temp)!=mpp.end()){
//             int length = count-mpp[temp];
//             cout<<"Length of the loop is : "<<length;
//             return head;
//         }
//         mpp[temp]=count;
//         temp=temp->next;
//     }
//     cout<<"No loop found";
//     return head;
//     }




// TODO: We are using tortoise & hair meathod , time comp is O(n) and space comp is O(1)

node *length_of_loop(node *head)
{
    if(head==nullptr || head->next==nullptr){
        cout<<"No loop";
        return head;}
    node *slow = head;
    node *fast = head;
    int n = 0;

    while (slow != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            n++;
            break;
        }
    }
    if (n == 1)
    {
        slow=slow->next;
        while (slow != fast)
        {
            n=n+1;
            slow = slow->next;
        }
        cout << "Length of the loop is : " << n;
        return head;
    }

    cout << "No loop in LL";
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

    length_of_loop(head);
}