class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head==nullptr || head->next==nullptr)
        return head;
        Node* prev=nullptr;
        Node* current = head;
        while(current!=nullptr){
            prev=current->prev;
            current->prev=current->next;
            current->next=prev;
            current=current->prev;
        }
        return prev->prev;
    }
};