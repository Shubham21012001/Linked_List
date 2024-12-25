#include <iostream>
#include <stack>
#include <vector>
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

 // Meathod 1 with time complexity O(2n)  (Using Stack)

// node *reverse_dll(node *head)
// {
//     stack<int> stack;
//     node *temp = head;
//     while (temp != nullptr)
//     {
//         stack.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp != nullptr)
//     {
//         temp->data = stack.top();
//         stack.pop();
//         temp=temp->next;
//     }
//     return head;
// }



//  Optimal code for reversing DLL :-  (reversing pointers) O(n)

node* reverse_dll(node* head){
     node* current = head;
     node* prev = nullptr;

     while(current!=nullptr){
        prev=current->back;
        current->back=current->next;
        current->next=prev;

        prev=current;
        current=current->back;
      
     }
      return prev;
}

int main()
{
    vector<int> arr = {9, 4, 7, 2};
    node *head = arr_to_doubly_ll(arr);
    head = reverse_dll(head);
    print(head);
}