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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        k%=len;
        temp=head;
        while(temp->next && k>0){
            if(temp->next->next==nullptr){
                ListNode* newNode = temp->next;
                newNode->next=head;
                temp->next=nullptr;
                head=newNode;
                k--;
                temp=head;
            }else{
                temp=temp->next;
            }
        }
        return head;
    }
};