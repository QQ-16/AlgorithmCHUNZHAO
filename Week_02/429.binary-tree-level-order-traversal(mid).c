/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10000
struct Node* g_queue[MAX_SIZE];
int g_front;
int g_tail;
void EnQueue(struct Node* node)
{
    g_queue[g_tail] = node;
    g_tail = (g_tail + 1) % MAX_SIZE;
    return;
}

struct Node* DeQueue()
{
    struct Node* node = g_queue[g_front];
    g_front = (g_front + 1) % MAX_SIZE;
    return node;
}

bool IsEmpty()
{
    if (g_front == g_tail) {
        return true;
    }
    return false;
}

int GetQueueNum()
{
    if (g_tail - g_front >= 0) {
        return g_tail - g_front;
    } else {
        return (g_tail + MAX_SIZE - g_front) % MAX_SIZE; 
    }
}

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes)
{
    int i;
    int j;
    int queueNum;
    struct Node* queueElement;
    int **result = NULL;

    g_front = 0;
    g_tail = 0;
    memset(g_queue, 0, sizeof(struct Node*) * MAX_SIZE);
    *returnSize = 0;

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (*returnColumnSizes == NULL) {
        return NULL;
    }
    memset(*returnColumnSizes, 0, sizeof(int) * MAX_SIZE);

    if (root == NULL) {
        return NULL;
    }

    result = (int **)malloc(sizeof(int *) * MAX_SIZE);
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, sizeof(int *) * MAX_SIZE);

    //根，入队列
    EnQueue(root);

    //循环出队
    while (!IsEmpty()) {
        queueNum = GetQueueNum();
        (*returnColumnSizes)[*returnSize] = queueNum;
        result[*returnSize] = (int *)malloc(sizeof(int) * queueNum);
        if (result[*returnSize] == NULL) {
            //是否需要释放其他内存恢复输出数据为NULL/returnsize为0/returnCol每列为0？
            return NULL;
        }
        for (i = 0; i < queueNum; i++) {
            queueElement = DeQueue();
            result[*returnSize][i] = queueElement->val;

            for (j = 0; j < queueElement->numChildren; j++) {
                EnQueue(queueElement->children[j]);
            }
        }
        (*returnSize)++;
    }
    return result;
}