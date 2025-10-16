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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a--; b--; //convert to 0 indexing
        ListNode* leftTail = list1;
        for(int i=0;i<a;i++) {
            leftTail = leftTail -> next;
        }
        cout<<"leftTail="<<leftTail->val<<endl;

        //we are at a-1 and we want to go to b+1
        //note the i<=b instead of i<b
        ListNode* rightHead = leftTail; 
        for(int i=a-1;i<=b;i++) {
            rightHead = rightHead -> next;
        }
        cout<<"rightHead="<<rightHead->val<<endl;

        ListNode* leftHead = list2; 
        cout<<"leftHead="<<leftHead->val<<endl;
        ListNode* rightTail = list2;
        while(rightTail->next) rightTail = rightTail -> next;
        cout<<"rightTail="<<rightTail->val<<endl;

        leftTail->next = leftHead;
        rightTail->next = rightHead;
        return list1;
    }
};