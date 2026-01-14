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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoSortedLL(ListNode* first, ListNode* second){

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(first && second){
            if(first->val <= second->val){
                temp->next = first;
                first = first->next;
            }
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }

        if(first){
            temp->next = first;
        }
        else{
            temp->next = second;
        }

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return head;

        ListNode* middle = findMiddle(head);
        ListNode* first = head;
        ListNode* second = middle->next;
        middle->next = NULL;

        first = sortList(first);
        second = sortList(second);
        
        return mergeTwoSortedLL(first, second);
    }
};