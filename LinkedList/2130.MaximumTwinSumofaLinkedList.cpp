// //Leetcode:2130. Maximum Twin Sum of a Linked List
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

 

// Example 1:


// Input: head = [5,4,2,1]
// Output: 6
// Explanation:
// Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
// There are no other nodes with twins in the linked list.
// Thus, the maximum twin sum of the linked list is 6. 
// Example 2:


// Input: head = [4,2,2,3]
// Output: 7
// Explanation:
// The nodes with twins present in this linked list are:
// - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
// - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
// Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
// Example 3:


// Input: head = [1,100000]
// Output: 100001
// Explanation:
// There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
 

// Constraints:

// The number of nodes in the list is an even integer in the range [2, 105].
// 1 <= Node.val <= 105

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
    //Approach: Find mind  of linkedlist using slow and fast pointer
    //then reverse mid to end part of linkedlist
    //then take sum of curr and mid . where uss will be pointing to head
    //do this until mid !=null and return max at last

    int pairSum(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        //mid =slow pointer 
        ListNode*curr=slow;
        //reverse linkedlist from mid to last
        ListNode* prev=NULL;
        ListNode*forward=NULL;
        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        //calculate ans
        curr=head;
        int ans=0;
        while(prev)
        {
            ans=max(ans  , curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return ans;
        
    }
};