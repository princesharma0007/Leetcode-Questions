double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int Size = nums1Size + nums2Size;
    int result[Size];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < nums1Size && j < nums2Size) {

        if (nums1[i] < nums2[j]) {
            result[k] = nums1[i];
            i++;
        } else {
            result[k] = nums2[j];
            j++;
        }

        k++;
    }

    while (i < nums1Size) {
        result[k] = nums1[i];
        i++;
        k++;
    }

    while (j < nums2Size) {
        result[k] = nums2[j];
        j++;
        k++;
    }

    if (Size % 2 == 1) {
        return result[Size / 2];
    } else {
        return (result[Size / 2 - 1] + result[Size / 2]) / 2.0;
    }
}