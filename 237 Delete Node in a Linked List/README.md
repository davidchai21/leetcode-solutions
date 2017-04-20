This question is... hard to say. Only know the node in the list can play tricky in this way.

If we delete the node directly by running *node=*node->next, we will have the space not freed. So a better way is to delete the next node:

ListNode* next=node->next;
*node=*node->next;
delete next;

Runtime: 6ms
