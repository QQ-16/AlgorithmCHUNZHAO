/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10000

int g_visited[MAX_SIZE];

void Place(int *nums, int numsSize, int level, int *temp, int **result, int *returnSize, int **returnColumnSizes)
{
    int j;

    if (level == numsSize) {
        result[*returnSize] = (int *)malloc(sizeof(int) * numsSize);
        memcpy(result[*returnSize], temp, sizeof(int) * numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (j = 0; j < numsSize; j++) {
        if (g_visited[j] == 1) {
            continue;
        }

        temp[level] = nums[j];
        g_visited[j] = 1;
        
        Place(nums, numsSize, level + 1, temp, result, returnSize, returnColumnSizes);
        g_visited[j] = 0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **result = NULL;
    int temp[numsSize];

    result = (int **)malloc(sizeof(int *) * MAX_SIZE);
    *returnSize = 0;
    memset(g_visited, 0, sizeof(int) * MAX_SIZE);
    memset(temp, 0, sizeof(int) * numsSize);

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * MAX_SIZE);
    memset(*returnColumnSizes, 0, sizeof(int) * MAX_SIZE);

    Place(nums, numsSize, 0, temp, result, returnSize, returnColumnSizes);

    return result;
}