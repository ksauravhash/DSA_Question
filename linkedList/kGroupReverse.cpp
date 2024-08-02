

class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

Node* reverse(Node* head, int k) {
  if(head == nullptr) {
    return nullptr;
  }

  Node* prev = nullptr;
  Node* cur = head;
  Node *next;
  int count = 0;
  while(count < k && cur != nullptr) {
    next= cur->next;
    cur->next = cur;
    prev = cur;
    cur = next;
    count++;
  }

  if(next != nullptr) {
    cur->next = reverse(next, k);
  }
  return prev;
}