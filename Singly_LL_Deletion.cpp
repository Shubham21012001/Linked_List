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
node *deletion_head(node *head)
{ // deletion of head
  node *temp = head;
  head = head->next;
  temp->next = nullptr;
  delete temp;
  return head;
}

node *deletion_tail(node *head)
{ // deletion of tail
  if (head == nullptr)
    return head;
  if (head->next == nullptr)
  {
    delete head;
    return head;
  }
  node *temp = head;
  while (temp->next->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = nullptr;
  return head;
}

node *deletion_position(node *head, int k)
{
  if (head == nullptr)
    return nullptr;
  int count = 0;
  if (k == 1)
  {
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  node *temp = head;
  node *prev = nullptr;
  while (temp)
  {
    count++;
    if (count == k)
    {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}

node *deletion_element(node *head, int el)
{
  if (head == nullptr)
    return nullptr;
  if (head->data == el)
  {
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
  }

  node *temp = head;
  node *prev = nullptr;

  while (temp != nullptr)
  {
    if (temp->data == el)
    {
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
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
  cout << count;
}

int main()
{
  vector<int> arr = {8, 2, 3, 4};
  node *head = arr_to_ll(arr);
  //  head=deletion_head(head);
  // head = deletion_tail(head);
  // head=deletion_position(head,4);
  // head=deletion_element(head,4);
  print(head);
}
