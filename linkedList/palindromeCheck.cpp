#include <vector>

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

/**
 * Approach 1
 * Solve by converting in into an array
 * The space and the time Complexity = O(n)
 */

bool checkPalindrome(Node *head)
{
  std::vector<int> nodes;

  Node *tmp = head;
  while (tmp != nullptr)
  {
    nodes.push_back(tmp->data);
    tmp = tmp->next;
  }
  int i = 0;
  int j = nodes.size() - 1;
  while (i < j)
  {
    if (nodes[i++] != nodes[j--])
      return false;
  }
  return true;
}

/**
 * Approach 2
 * Find the middle
 * Reverse the nodes after that
 * Compare the nodes from head and after the middle
 * Time Complexity = O(n)
 * Space Complexity = O(1)
 */

Node *findMiddle(Node *head)
{
  if(head == nullptr)
    return nullptr;

  Node *slowPtr = head;
  Node* fastPtr = head->next;
  while(fastPtr != nullptr) {
    fastPtr= fastPtr->next;
    if(fastPtr->next != nullptr)
      fastPtr= fastPtr->next;
    slowPtr = slowPtr->next;
  }
  return slowPtr;
}

Node *reverse(Node *head) {
  if(head == nullptr)
    return nullptr;
  Node *tmp = head;
  Node *prev = nullptr;
  while(tmp != nullptr) {
    Node *tmp2 = head->next;
    tmp->next = prev;
    prev = tmp;
    tmp = tmp2;
  }
  return prev;
}

bool checkPalindrome2(Node *head)
{

  if(head == nullptr || head->next == nullptr)
    return true;


  Node *hd = head;
  Node *middle = findMiddle(head)->next;

  while(hd != nullptr && middle != nullptr) {
    if(hd->data != hd->data)
      return false;
  }
  return true;
  
  
}