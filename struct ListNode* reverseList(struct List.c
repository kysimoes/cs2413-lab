struct ListNode* reverseList(struct ListNode* head) {
    // Base case: if the list is empty or has only one node, return head
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Count the number of nodes in the list
    int length = 0;
    struct ListNode* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    // Swap nodes from the beginning to the end
    for (int i = 0; i < length / 2; i++) {
        // Find the i-th node from the beginning
        struct ListNode* start = head;
        for (int j = 0; j < i; j++) {
            start = start->next;
        }

        // Find the i node from the end
        struct ListNode* end = head;
        for (int j = 0; j < length - i - 1; j++) {
            end = end->next;
        }

        // Swap the values of the two nodes
        int temp = start->val;
        start->val = end->val;
        end->val = temp;
    }

    return head;
}