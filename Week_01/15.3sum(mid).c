/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define CLOUMN_NUM 3

int IntCompare(const void* a, const void* b)
{
    return *(int *)a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i;
    int onebase;
    int left;
    int right;
    int sum;
    int **result = NULL;

    qsort(nums, numsSize, sizeof(int), IntCompare);
    *returnSize = 0;

    if (numsSize < 3) {
        return NULL;
    }

    /* 注意组合结果的数量 */
    result = (int **)malloc(sizeof(int *) * (numsSize * numsSize)); 
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, sizeof(int *) * numsSize);

    (*returnColumnSizes) = (int *)malloc(sizeof(int)* (numsSize * numsSize));
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    for (i = 0; i < (numsSize * numsSize); i++) {
        (*returnColumnSizes)[i] = CLOUMN_NUM;
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            return result;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        onebase = i;
        left = onebase + 1;
        right = numsSize - 1;
        while (left < right) {
            sum = nums[onebase] + nums[left] + nums[right];
            if (sum == 0) {
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                result[*returnSize] = (int *)malloc(sizeof(int) * CLOUMN_NUM);
                if (result[*returnSize] == NULL) {
                    return NULL;
                }
                result[*returnSize][0] = nums[onebase];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;
                left++;
                right--;
            } else if (sum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }

    return result;
}