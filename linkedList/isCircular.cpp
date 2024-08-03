class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};


bool isCircular(Node* head) {
  if(head == nullptr)
    return false;
  Node * cur = head;
  while(cur != nullptr || cur != head) {
    cur = cur->next;
  }
  if(cur == nullptr)
    return false;
  return true;
}