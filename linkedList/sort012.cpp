

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

void sort012(Node *head)
{
  int zero, one, two;
  zero = one = two = 0;

  Node *tmp = head;
  while (tmp != nullptr)
  {
    if (tmp->data == 0)
      zero++;
    else if (tmp->data == 1)
      one++;
    else if (tmp->data == 2)
      two++;

    tmp = tmp->next;
  }
  tmp = head;
  while (tmp != nullptr)
  {
    if (zero != 0)
    {
      tmp->data = 0;
      zero--;
    }
    else if (one != 0)
    {
      tmp->data = 1;
      one--;
    }
    else
    {
      tmp->data = 2;
      two--;
    }
    tmp = tmp->next;
  }
}

/**
 * Approach 2
 */

/**
 * Create linked list for 0,1,2 and merge them
 */

void insertNode(Node *&head, Node *&tail, int value)
{
  if (head == nullptr)
  {
    head = tail = new Node(value);
  }
  else
  {
    tail->next = new Node(value);
    tail = tail->next;
  }
}

Node* sort012_2(Node *head)
{
  Node *zeroHead, *oneHead, *twoHead;
  Node *zerotail, *onetail, *twotail;
  zeroHead = zerotail = oneHead = onetail = twoHead = twotail = nullptr;

  Node *tmp = head;
  while (tmp != nullptr)
  {
    if (tmp->data == 0)
    {
      insertNode(zeroHead, zerotail, 0);
    }
    else if (tmp->data == 1)
    {
      insertNode(zeroHead, zerotail, 1);
    }
    else
    {
      insertNode(zeroHead, zerotail, 2);
    }
    tmp = tmp->next;
  }
  if(zeroHead != nullptr) {
    if(oneHead != nullptr) {
      zerotail->next= oneHead;
      if(twoHead != nullptr) {
        onetail->next = twoHead;
      }
    }else if(twoHead!= nullptr) {
      zerotail->next = twoHead;
    }
    return zeroHead;
  }else {
    if(oneHead != nullptr) {
      if(twoHead!=nullptr) {
        onetail->next = twoHead;
      }
      return oneHead;
    }else {
      return twoHead;
    }
  }
}