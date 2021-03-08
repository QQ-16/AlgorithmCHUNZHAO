#define MAX_SIZE 1000

typedef struct STACK_ELEMENT{
    int high;
    int position;
};

struct STACK_ELEMENT g_stack[MAX_SIZE];
int g_top;

#define MIN_VALUE(a, b) ((a) < (b) ? (a) : (b))

void PushStack(int position, int high) 
{
    g_top += 1;
    g_stack[g_top].position = position;
    g_stack[g_top].high = high;
    return;
}

struct STACK_ELEMENT PopStack()
{
    struct STACK_ELEMENT e = {0};
    if (g_top == -1) {
        return e;
    }

    g_top -= 1;
    return g_stack[g_top + 1];
}

int CalcSum(int i, int *height, struct STACK_ELEMENT *curElement) {
    int left;
    int right;
    int heightVal;
    int sum;

    if (g_top == -1) {
        return 0;
    }
    left = g_stack[g_top].position;
    right = i;
    heightVal = MIN_VALUE(height[i], g_stack[g_top].high) - curElement->high;

    sum = (right - left - 1) * heightVal;
    return sum;
}

int trap(int* height, int heightSize){
    int i;
    int sum = 0;
    struct STACK_ELEMENT curElement = {0};

    g_top = -1;
    memset(g_stack, 0, sizeof(struct STACK_ELEMENT) * MAX_SIZE);

    if (heightSize == 0) {
        return sum;
    }

    PushStack(0, height[0]);

    for (i = 1; i < heightSize; i++) {
        while (g_top != -1) {
            if (height[i] > g_stack[g_top].high) {
                curElement = PopStack();
                sum += CalcSum(i, height, &curElement);
            } else {
                break;
            }
        }
        PushStack(i, height[i]);
    }

    return sum;
}