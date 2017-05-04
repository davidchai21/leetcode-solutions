class Solution {
private:
    size_t lengthOfList(ListNode* l) {
        size_t cnt = 0;
        while (l != NULL) {
            l = l->next;
            ++cnt;
        }
        return cnt;
    }
    
    TreeNode* construct(ListNode** head, size_t length) {
        // some base conditions
        if (length == 0) {
            return NULL;
        } else if (length == 1) {
            TreeNode* parent = new TreeNode((*head)->val);
            *head = (*head)->next;
            return parent;
        }
   
        size_t tmp_len = length - 1;
        size_t right_len = tmp_len / 2;
        size_t left_len = tmp_len - tmp_len / 2;
        TreeNode* left_child = construct(head, left_len);
        TreeNode* parent = new TreeNode((*head)->val);
        *head = (*head)->next;
        parent->left = left_child;
        parent->right = construct(head, right_len);
        return parent;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        size_t len = lengthOfList(head);
        return construct(&head, len);
    }
};
