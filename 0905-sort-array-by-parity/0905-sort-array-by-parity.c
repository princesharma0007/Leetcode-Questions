int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = numsSize - 1;

    int* arr = malloc(numsSize * sizeof(int));

    for (int k = 0; k < numsSize; k++) {
        if (nums[k] % 2 == 0) {
            arr[i++] = nums[k];
        } else {
            arr[j--] = nums[k];
        }
    }

    *returnSize = numsSize;
    return arr;
}