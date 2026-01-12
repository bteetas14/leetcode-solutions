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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL) return NULL;

        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            cnt++;
        }

        int pos = cnt - n;
        temp = head;

        if(pos==0) return head->next;

        while(pos>1){
            temp = temp->next;
            pos--;
        }

        temp->next = temp->next->next;
        return head;
    }
};