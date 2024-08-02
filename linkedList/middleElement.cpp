
class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};


int getLength(Node * head) {
  int count = 0;
  while(head->next!= nullptr ) {
    count++;
    head =head->next;

  }
  return count;
}

Node * getMiddleNode(Node *head) {
  Node *cpy = head;
  int length = getLength(cpy);
  int mid = length / 2 +1;
  while(mid > 1) {
    cpy = cpy->next;
  }
  return cpy;
}

// Optmized version of getMiddleNode

Node* getMiddleNodeOpt(Node * head) {
  if(head == nullptr)
    return nullptr;
  if(head->next == nullptr)
    return head;
  if(head->next->next= nullptr)
    return head->next;
  //Moves two at a time
  Node* fast = head->next;
  // Moves one at a time
  Node* slow = head;

  while(fast != nullptr) {
    fast = fast->next;
    if(fast != nullptr)
      fast = fast->next;
    slow = slow->next;
  }
  return slow;
}