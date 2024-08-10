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

Node *findMid(Node *head)
{
  if (head == nullptr || head->next == nullptr)
    return head;

  Node *slow = head;
  Node *fast = head->next;

  while (fast != nullptr)
  {
    fast = fast->next;
    if (fast->next != nullptr)
      fast = fast->next;
    slow = slow->next;
  }
  return slow;
}

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

Node *merge(Node *left, Node *right)
{

  if (left == nullptr)
    return right;
  if (right == nullptr)
    return left;

  Node *ansHead, *ansTail;
  Node *tmp1 = left;
  Node *tmp2 = right;

  while (tmp1 != nullptr && tmp2 != nullptr)
  {
    if (tmp1->data > tmp2->data)
    {
      insertAtTail(ansHead, ansTail, tmp2->data);
      tmp1 = tmp1->next;
    }
    else
    {
      insertAtTail(ansHead, ansTail, tmp2->data);
      tmp2 = tmp2->next;
    }
  }
  while (tmp1 != nullptr)
  {
    insertAtTail(ansHead, ansTail, tmp2->data);
    tmp1 = tmp1->next;
  }
  while (tmp2 != nullptr)
  {
    insertAtTail(ansHead, ansTail, tmp2->data);
    tmp2 = tmp2->next;
  }
  return ansHead;
}

Node *mergeSort(Node *head)
{
  if (head == nullptr || head->next == nullptr)
  {
    return head;
  }
  Node *mid = findMid(head);

  Node *left = head;
  Node *right = mid->next;
  mid->next = nullptr;

  mergeSort(left);
  mergeSort(right);

  return merge(left, right);
}