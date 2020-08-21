// 109. Convert Sorted List to Binary Search Tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return BSTNode(head, nullptr);
    }
private :
    TreeNode* BSTNode(ListNode* head, ListNode* tail) {
        
        if(head==tail) {
            return nullptr;
        }
        else if(head->next == tail) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode* mid  = head;
        ListNode* temp = head;
        
        while(temp!=tail && temp->next!=tail) {
            mid = mid->next;
            temp = temp->next->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = BSTNode(head, mid);
        root->right = BSTNode(mid->next, tail);
        return root;
    }
};