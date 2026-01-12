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
    ListNode* reverseLL(ListNode* head){
        ListNode* newHead = nullptr;

        while(head){
            ListNode* nex = head->next;
            head->next = newHead;
            newHead = head;
            head = nex;
        }
        return newHead;
    }

    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* first = head;
        ListNode* second = reverseLL(slow);

        while(first && second){
            if(first->val != second->val){
                return false;
            }

            first = first->next;
            second = second->next;
        }
        return true;
    }
};