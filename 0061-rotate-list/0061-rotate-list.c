/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct ListNode* temp = head;
    int n = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }
    k=k % n;
    if (k == 0)
        return head;
    temp->next = head;
    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    struct ListNode* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}