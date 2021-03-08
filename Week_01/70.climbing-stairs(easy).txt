#define MAX_SIZE 100000
int g_visited[MAX_SIZE];

int climbCount(int n)
{
    if (g_visited[n] != 0) {
        return g_visited[n];
    }
    g_visited[n] = climbCount(n - 1) + climbCount(n - 2);
    return g_visited[n];
}

int climbStairs(int n)
{
    memset(g_visited, 0 ,sizeof(int) * MAX_SIZE);
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n ==2) {
        return 2;
    }
    g_visited[0] = 0;
    g_visited[1] = 1;
    g_visited[2] = 2;
    
    return climbCount(n);
}