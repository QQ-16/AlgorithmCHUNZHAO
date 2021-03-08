/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int position;
    int tempSum;
    int add = 1;
    int *result;

    for (position = digitsSize - 1; position >= 0; position--) {
        tempSum = 0;
        tempSum = digits[position] + add;
        /* 考虑进位 */
        if (tempSum < 10) {
            digits[position] = tempSum;
            *returnSize = digitsSize;
            return digits;
        } else {
            digits[position] = tempSum % 10;
        }
    }

    result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(result, 0, sizeof(int) * (digitsSize + 1));
    memcpy(&result[1], digits, sizeof(int) * digitsSize);
    result[0] = 1;
    *returnSize = digitsSize + 1;
    return result;
}
