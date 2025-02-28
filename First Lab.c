struct ListNode* removeElements(struct ListNode* head, int val) {
    // Base case: if the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    // Recursively remove elements from the rest of the list
    head->next = removeElements(head->next, val);

    // If the current node has the value `val`, skip it
    if (head->val == val) {
        struct ListNode* nextNode = head->next;
        free(head); // Free the memory of the node to be removed
        return nextNode;
    }

    // If the current node does not have the value `val`, keep it
    return head;
}
