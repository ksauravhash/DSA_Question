#include <unordered_map>

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }
};

void removeSortedDuplicates(Node *head)
{
  if (head == nullptr)
    return;

  Node *tmp = head;

  while (tmp != nullptr)
  {
    if (tmp->next != nullptr && tmp->data == tmp->next->data)
    {
      Node *tmp2 = tmp->next;
      tmp->next = tmp2->next;
      delete tmp2;
    }
    tmp = tmp->next;
  }
}

/**
 * By searching for duplicates again and again
 * Time Complexity: O(n^2)
 */

void removeUnsortedDuplicates(Node *head)
{
  if (head == nullptr)
    return;

  Node *cur = head;
  while (cur != nullptr)
  {
    Node *tmp = cur->next;
    while (tmp != nullptr)
    {
      if (tmp->data == cur->data)
      {
        Node *tmp2 = tmp->next;
        tmp->next = tmp2->next;
        delete tmp2;
      }
      tmp = tmp->next;
    }
    cur = cur->next;
  }
}

void removeUnsortedDuplicates3(Node *head)
{
  if (head == nullptr)
    return;

  Node *cur = head;
  std::unordered_map<int, bool> visited;
  while (cur != nullptr)
  {
    if (visited[cur->data])
    {
      Node *tmp2 = cur->next;
      cur->next = tmp2->next;
      delete tmp2;
    }
    visited[cur->data] = true;
    cur = cur->next;
  }
}