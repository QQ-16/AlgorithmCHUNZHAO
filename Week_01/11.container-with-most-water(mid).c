#define MIN(x, y) ((x) <= (y) ? (x) : (y))

int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int curArea = 0;
    int maxArea = 0;

    while (i < j) {
        if (height[i] <= height[j]) {
            curArea = height[i] * (j - i);
            maxArea = maxArea > curArea ? maxArea : curArea;
            i++;
        } else {
            curArea = height[j] * (j - i);
            maxArea = maxArea > curArea ? maxArea : curArea;
            j--;
        }
    }

    return maxArea;
}