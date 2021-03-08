void moveZeroes(int* nums, int numsSize){
    int i = 0;
    int j;
    int temp;

    while (i < numsSize) {
        if (nums[i] == 0) {
            j = i + 1;
            while (nums[j] != 0 && j < numsSize) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
        i++;
    }
    return;
}