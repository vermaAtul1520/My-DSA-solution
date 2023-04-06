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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int count = 0;
        while(cur!=NULL){
           count++;
           cur = cur->next;
        }
        if(count<k){
           return head;
        }
        cur=head;
        int c=0;
        while(cur!=NULL && c<k){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            c++;
        }
        
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        
        return prev; 
    }
};