int missingNumber(int* nums, int numsSize) {
    int freq[numsSize + 1];

    for (int i = 0; i <= numsSize; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    for (int i = 0; i <= numsSize; i++) {
        if (freq[i] == 0) {
            return i;
        }
    }

    return -1;
}