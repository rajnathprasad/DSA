Node* prev = node->back;
Node* front = node->next;

if (prev != nullptr)
    prev->next = front;
else
    head = front;

if (front != nullptr)
    front->back = prev;

delete node;