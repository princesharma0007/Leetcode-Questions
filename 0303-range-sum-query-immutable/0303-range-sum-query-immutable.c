typedef struct {
    int *sum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *create= malloc(sizeof(NumArray));
    create->sum = malloc(numsSize * sizeof(int));
    create->sum[0]=nums[0];
for (int i = 1; i < numsSize; i++) {
        create->sum[i] = create->sum[i - 1] + nums[i];
    }
    return create;
}

int numArraySumRange(NumArray* create, int left, int right) {
        if (left == 0)
        return create->sum[right];

    return create->sum[right] - create->sum[left - 1];
}

void numArrayFree(NumArray* create) {
       free(create->sum);
    free(create);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/