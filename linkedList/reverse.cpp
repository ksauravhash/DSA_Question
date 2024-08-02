
class Node {
  public:
    int data;
    Node* next;

  Node(int data) {
    this->data = data;
    next = nullptr;
  }
};

void reverse(Node *&head, Node *cur, Node* prev) {
  if(cur == nullptr) {
    head = prev;
    return;
  }

  reverse(head, cur->next, cur);
  cur->next = prev;
}

Node* reverse1(Node *head) {
  if(head->next == nullptr || head == nullptr)
    return head;
  Node* newHead = reverse1(head->next);
  head->next->next= head;
  head->next = nullptr;

  return newHead;
}