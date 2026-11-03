#include <stdlib.h>
int* nextGreaterElement(int* nums1, int nums1Size,int* nums2, int nums2Size,int* returnSize) {

    int stack[1000];
    int top = -1;

    int next[10001];

    for (int i = 0; i <= 10000; i++) {
        next[i] = -1;
    }

    for (int i = nums2Size - 1; i >= 0; i--) {

        while (top >= 0 && stack[top] <= nums2[i]) {
            top--;
        }

        if (top != -1) {
            next[nums2[i]] = stack[top];
        }

        stack[++top] = nums2[i];
    }

    int* ans = malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = next[nums1[i]];
    }

    return ans;
}
