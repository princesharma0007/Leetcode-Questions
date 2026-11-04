int* twoSum(int* arr, int numbersSize, int target, int* returnSize) {
    int index1 = 0;
    int index2 = numbersSize - 1;

    while (index1 < index2) {
        int sum = arr[index1] + arr[index2];

        if (sum == target) {
            int* result = malloc(2 * sizeof(int));

            result[0] = index1 + 1;
            result[1] = index2 + 1;

            *returnSize = 2;
            return result;
        }
        else if (sum > target) {
            index2--;
        }
        else {
            index1++;
        }
    }

    *returnSize = 0;
    return NULL;
}
