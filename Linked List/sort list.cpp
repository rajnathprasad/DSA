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
    ListNode* merge2(ListNode* list1, ListNode* list2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (list1 != nullptr)
        temp->next = list1;
    else
        temp->next = list2;

    return dummyNode->next;
}
    ListNode* findMiddle(ListNode* head){
        if(head==nullptr || head->next==nullptr)
        return head;
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
        return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next=nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge2(leftHead, rightHead);


    }
};