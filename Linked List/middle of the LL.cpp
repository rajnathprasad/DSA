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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count=1;
        int trav=0;
        while(temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        temp=head;
        while(trav<count/2){
            temp=temp->next;
            trav++;
        }
        return temp;
    }
};