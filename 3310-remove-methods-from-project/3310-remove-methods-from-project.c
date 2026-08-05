/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* remainingMethods(int n, int k, int** invocations, int invocationsSize, int* invocationsColSize, int* returnSize) {
    int *head = (int *)malloc(n * sizeof(int));
    int *to = (int *)malloc(invocationsSize * sizeof(int));
    int *next = (int *)malloc(invocationsSize * sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    int idx = 0;
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];
        to[idx] = v;
        next[idx] = head[u];
        head[u] = idx++;
    }

    // Find suspicious methods
    bool *suspicious = (bool *)calloc(n, sizeof(bool));
    int *queue = (int *)malloc(n * sizeof(int));

    int front = 0, rear = 0;
    queue[rear++] = k;
    suspicious[k] = true;

    while (front < rear) {
        int u = queue[front++];

        for (int i = head[u]; i != -1; i = next[i]) {
            int v = to[i];
            if (!suspicious[v]) {
                suspicious[v] = true;
                queue[rear++] = v;
            }
        }
    }

    // Check if any non-suspicious method invokes a suspicious one
    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];

        if (!suspicious[u] && suspicious[v]) {
            int *ans = (int *)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++)
                ans[j] = j;
            *returnSize = n;

            free(head);
            free(to);
            free(next);
            free(suspicious);
            free(queue);

            return ans;
        }
    }

    // Return remaining methods
    int *ans = (int *)malloc(n * sizeof(int));
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i])
            ans[cnt++] = i;
    }

    *returnSize = cnt;

    free(head);
    free(to);
    free(next);
    free(suspicious);
    free(queue);

    return ans;
}