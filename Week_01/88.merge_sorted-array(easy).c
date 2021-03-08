int IntCompare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    memcpy(nums1 + m, nums2, sizeof(int) * n);
    qsort(nums1,  m + n, sizeof(int), IntCompare);
    return;
}