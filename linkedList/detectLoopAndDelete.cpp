#include <unordered_map>

class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

/**
 * Approach 1
 */

/**
 * Checks for a cycle by checking if each
 * node has been visited more than once.
 */
bool hasLoop(Node *head) {
  if(head == nullptr) 
    return false;
  std::unordered_map<Node*, bool> visited;

  Node *tmp = head;
  while(tmp != nullptr) {
    if(visited[tmp]) {
      return true;
    }
    visited[tmp] = true;
    tmp = tmp->next;
  }
  return true;

}

/**
 * Approach 2
 */

/**
 * Floyd's Cycle detection algorithm
 * Fast and slow pointer
 * Fast pointer 2x slow  ponter
 * If fast pointer and slow pointer meets then a cycle is detected
 * else if null is detected by fast pointer then there is no cycle
 */
Node* floydCycleDetect(Node *head) {
  if(head == nullptr)
    return nullptr;
  Node* fast = head;
  Node* slow = head;

  while(fast != nullptr) {
    fast = fast->next;
    if(fast != nullptr)
      fast =fast->next;
    slow = slow->next;
    if(fast == slow)
      return slow;
  }
  return nullptr;
}

/**
 * The distance of the starting node of the cyle from the head is A
 * The distance of the intersection from the starting node of the cycle is B
 * The distance of the whole cycle is C
 * By Floyd's algorithm
 * A + B = C
 */

Node* getStartingNode(Node *head) {
  if(head == nullptr)
    return nullptr;

  Node *intersection = floydCycleDetect(head);
  if(intersection == nullptr)
    return nullptr;
  Node *slow = head;

  while(slow != intersection) {
    slow = slow->next;
    intersection = intersection->next;
  }

  return slow;
}

void removeCycle(Node *head) {
  if(head == nullptr)
    return;

  Node *startNode = getStartingNode(head);
  if(startNode)
    return;
  Node *tmp = startNode;
  while(tmp->next != startNode) {
    tmp= tmp->next;
  }
  tmp->next = nullptr;
}