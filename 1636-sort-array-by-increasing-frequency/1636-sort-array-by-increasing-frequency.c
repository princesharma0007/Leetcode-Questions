/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int freqpos[101] = {0};
    int freqneg[101] = {0};

    int* sort = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0) {
            freqpos[nums[i]]++;
        } else {
            freqneg[-nums[i]]++;
        }
    }

    int k = 0;

    for (int freq = 1; freq <= numsSize; freq++) {
        for (int i = 100; i >= 0; i--) {
            if (freqpos[i] == freq) {
                for (int j = 0; j < freq; j++) {
                    sort[k++] = i;
                }
            }
        }

        for (int i = 1; i <= 100; i++) {
            if (freqneg[i] == freq) {
                for (int j = 0; j < freq; j++) {
                    sort[k++] = -i;
                }
            }
        }
    }

    return sort;
}
