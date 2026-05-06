// //leetcode: 61. Rotate List
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109


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

        int l=0;
        ListNode* temp =head;

        if(head==NULL)
        {
            return NULL;
        }
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        k=k%l;
        
        ListNode* currentHead=head;
       temp=head;
        ListNode * prev=head;
        while(k!=0)
        {
            temp =currentHead;
            while(temp->next!=NULL)
            {   
                prev=temp;
                temp=temp->next;
            }
            temp->next=currentHead;
            prev->next=NULL;
            currentHead=temp;

            k--;
        }
        return currentHead;
        
    
        
    }
};


