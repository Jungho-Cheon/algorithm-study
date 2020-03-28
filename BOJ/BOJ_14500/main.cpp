#include <iostream>

using namespace std;

typedef struct point
{
    int x, y;
} point;

point STACK[5];
int top = -1;

point pop()
{
    return STACK[top--];
}

void push(int x, int y)
{
    STACK[++top].x = x;
    STACK[top].y = y;
}

bool visit[501][501] = {
    0,
};
int MAP[501][501];
int result = 0;
int N, M;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void DFS(int x, int y, int sum, int depth)
{
    sum += MAP[x][y];

    if (depth == 1)
    {
        if (sum > result)
        {
            result = sum;
        }
        return;
    }

    push(x, y);
    visit[x][y] = true;

    for (int k = 0; k <= top; k++)
    {
        for (int a = 0; a < 4; a++)
        {
            int nx = STACK[k].x + dx[a];
            int ny = STACK[k].y + dy[a];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (!visit[nx][ny])
                DFS(nx, ny, sum, depth - 1);
        }
    }

    visit[x][y] = false;
    pop();

    return;
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &MAP[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            DFS(i, j, 0, 4);
        }
    }

    printf("%d", result);

    return 0;
}