

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

Node *mergeTwo(Node *head1, Node *head2)
{

  if (head1 == nullptr)
    return head2;
  if (head2 == nullptr)
    return head1;

  Node *tmp1 = head1;
  Node *tmp2 = head2;

  while (tmp1 != nullptr && tmp2 != nullptr)
  {
    if (tmp1->next != nullptr)
    {
      if (tmp1->data < tmp2->data && tmp2->data < tmp1->next->data)
      {
        // Insert the node in between two nodes
        Node *tmp = tmp1->next;
        Node *tmp_2 = tmp2->next;
        tmp1->next = tmp2;
        tmp2->next = tmp;
        tmp2 = tmp_2;
      }
    }else {
      tmp1->next = tmp2;
      break;
    }
    tmp1 = tmp1->next;
  }
  return head1;
}