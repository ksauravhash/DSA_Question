class Node
{
public:
  int data;
  Node *next;
  Node *right;

  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }
};

Node *mergeTwoSorted(Node *one, Node *two)
{

  if (one == nullptr)
    return two;
  if (two == nullptr)
    return one;

  Node *h1, *h2, *tmp1, *tmp2;

  if (one->data < two->data)
  {

    tmp1 = h1 = one;
    tmp2 = h2 = two;
  }
  else
  {
    tmp1 = h1 = two;
    tmp2 = h2 = one;
  }

  while (tmp1 != nullptr && tmp2 != nullptr)
  {
    if (tmp1->next != nullptr)
    {
      if (tmp1->data < tmp2->data && tmp2->data < tmp1->next->data)
      {
        Node *next = tmp1->next;
        Node *next2 = tmp2->next;
        tmp1->next = tmp2;
        tmp2->next = next;
        tmp2 = next2;
      }
      else
      {
        tmp1->next = tmp2;
      }
      tmp1 = tmp1->next;
    }
  }

  return h1;
}


Node *flatten(Node *head) {
  Node *down = head;
  // down->next =nullptr;
  Node *right = flatten(head->right);

  return mergeTwoSorted(down, right);
}