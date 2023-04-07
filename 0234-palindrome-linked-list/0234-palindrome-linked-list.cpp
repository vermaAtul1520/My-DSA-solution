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
    ListNode* reverse(ListNode* &cur){
        ListNode* p=NULL;
        ListNode* c=cur;
        while(c){
            ListNode* nxt=c->next;
            c->next=p;
            p=c;
            c=nxt;
        }
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode* cur=head;
        ListNode* prev=NULL;
        while(cur!=NULL){
            n++;
            cur=cur->next;
            
        }
        cur=head;
        int k=n/2;
        while(k--){
            prev=cur;
            cur=cur->next;
        }
        if(n%2){
            prev=cur;
            cur=cur->next;
        }
        prev->next=reverse(cur);
        cur=head;
        ListNode* mid=prev->next;
        // cout<<mid->val<<" ";
        while(mid){
            if(cur->val!=mid->val) return false;
            cur=cur->next;
            mid=mid->next;
        }
        return true;
    }
};