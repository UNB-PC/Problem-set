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
        ListNode* nth = head;
        ListNode* current = head;
        int range = 1;

        while(current->next != nullptr){
            current = current->next;
            if(range < n+1)
                range++;
            else
                nth = nth->next;
        }
        
        //list has more than n elements
        if(range == n+1){
            ListNode* pop = nth->next;
            nth->next = pop->next;
            pop->next = nullptr;
        }
        else if(range == n){
            // nth element is the head
            head = nth->next;
            nth->next = nullptr;
        }

        return head;       
    }
};
