/* 求出每行最多的连续1的个数 */
void calcMinHigh(int *minHigh, int j, int *heights) {
    if (heights[j] < *minHigh) {
        *minHigh = heights[j];
    }
    return;
}

int largestRectangleArea(int* heights, int heightsSize){
    int areaMax = 0;
    int areaMaxTemp;
    int i, j;
    int minHigh;

    if (heights == NULL || heightsSize == 0) {
        return 0;
    }

    for (i = 0; i < heightsSize; i++) {
        minHigh = INT_MAX;
        for (j = i; j < heightsSize; j++) {
            /* 计算i-j之间的最大面积-高度应该为这段中的最低 */
            calcMinHigh(&minHigh, j, heights);
            /* 最大面积 */
            areaMaxTemp = minHigh*(j-i+1);
            if (areaMaxTemp > areaMax) {
                areaMax = areaMaxTemp;
            }
        }

    }

    return areaMax;
}