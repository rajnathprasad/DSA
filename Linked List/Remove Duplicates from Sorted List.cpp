/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* prev=head;
        ListNode* temp=prev->next;
        while(temp){
            if(prev->val==temp->val){
                ListNode* nextNode=temp->next;
                prev->next=nextNode;
                delete temp;
                temp=nextNode;
            }else{
                prev=prev->next;
                temp=temp->next;
            }
        }
        return head;
    }
};