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

Node *reverse(Node *head)
{
  if (head == nullptr)
    return head;
  Node *cur = head;
  Node *prev = nullptr;

  while (cur != nullptr)
  {
    Node *tmp = cur->next;
    tmp->next = prev;
    prev = cur;
    cur = tmp;
  }
  return prev;
}

void *insertAtTail(Node *&head,Node *&tail, int data) {
  if(tail == nullptr) {
    head = tail = new Node(data);
    return;
  }

  tail->next = new Node(data);
  tail = tail->next;

}

Node *add(Node *n1, Node *n2)
{
  int carry = 0;
  Node *ansHead;
  Node *ansTail;
  while(n1 != nullptr || n2 != nullptr || carry != 0) {

    int value1 = 0;
    if(n1 != nullptr)
      value1 = n1->data;

    int value2 = 0;
    if(n2 != nullptr)
      value2 = n2->data;
    

    int sum = carry + value1 + value2;;
    int digit = sum %10;
    insertAtTail(ansHead, ansTail, digit);

    carry = sum / 10;
    if(n1!=nullptr)
      n1 = n1->next;
    if(n2!=nullptr)
      n2 = n2->next;
  }
  return ansHead;
}

Node *addTwoNumbers(Node *head1, Node *head2)
{
  Node *h1 = reverse(head1);
  Node *h2 = reverse(head2);

  Node *ans = add(h1,h2);

  return reverse(ans);
}