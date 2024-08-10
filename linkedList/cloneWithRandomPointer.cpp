#include <unordered_map>

class Node
{
public:
  int data;
  Node *next;
  Node *random;

  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }
};

void *insertAtTail(Node *&head, Node *&tail, int data)
{
  if (tail == nullptr)
  {
    head = tail = new Node(data);
    return;
  }

  tail->next = new Node(data);
  tail = tail->next;
}

/**
 * Approach 1
 * Copy the nodes first normally
 * For each node match the random node
 * Time complexity = O(n^2)
 * Space complexity = O(1)
 */
Node *clone(Node *head)
{
}

/**
 * Approach 2
 * Copy the nodes first normally and store the mapping of original node to clone node
 * For each node get the mapping for it's random link
 * Time complexity = O(n)
 * Space complexity = O(n)
 */
Node *clone2(Node *head)
{
  std::unordered_map<Node *, Node *> map;

  if (head == nullptr)
    return nullptr;

  Node *tmp = head;
  Node *cloneHead, *cloneTail;

  while (tmp != nullptr)
  {
    insertAtTail(cloneHead, cloneTail, tmp->data);
    map[tmp] = cloneTail;
    tmp = tmp->next;
  }

  tmp = head;
  Node *tmp2 = cloneHead;
  while (tmp != nullptr)
  {
    tmp2->random = map[tmp->random];
    tmp2 = tmp2->next;
    tmp = tmp->next;
  }

  return cloneHead;
}

/**
 * Approach 3
 * Copy the original nodes
 * Insert the cloned nodes in between the original nodes
 * For each clone node set clone nodes' random = original node->random->next
 * Extract the cloned nodes from the merged nodes
 */

Node *clone3(Node *head)
{
  Node *tmp = head;
  if (tmp == nullptr)
    return nullptr;

  // Copy the original nodes
  Node *cloneHead, *cloneTail;
  while (tmp != nullptr)
  {
    insertAtTail(cloneHead, cloneTail, tmp->data);
    tmp = tmp->next;
  }

  // Insert the cloned nodes in between the original nodes
  tmp = head;
  Node *cTemp = cloneHead;
  while (tmp != nullptr)
  {
    Node *next = tmp->next;
    tmp->next = cTemp;
    cTemp = cTemp->next;
    tmp->next->next = next;
    tmp = next;
  }
  tmp = head;
  while (tmp != nullptr)
  {
    tmp->next->random = tmp->random->next;
    tmp = tmp->next->next;
  }

  // Extract the nodes back
  tmp = head;
  cTemp = cloneHead;
  while(tmp != nullptr) {
    tmp ->next = tmp->next->next;
    if(cTemp->next->next != nullptr)
      cTemp->next = cTemp->next->next;
    else
      cTemp->next = nullptr;
    tmp = tmp->next;
    cTemp = cTemp->next;
  }
  return cloneHead;
}

