class Solution {
public:
    ListNode* rev(ListNode* head){
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* newHead=rev(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* temp=head;
        int cnt = 1;
        while(cnt<k && temp){
            temp=temp->next;
            cnt++;
        }
        if(temp == nullptr) return head;
        ListNode* nextHead = temp->next;
        temp->next = nullptr;
        ListNode* newHead=rev(head);
        head->next=reverseKGroup(nextHead, k);
        return newHead;
    }
};