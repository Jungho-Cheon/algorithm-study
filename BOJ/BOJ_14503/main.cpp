#include <iostream>

using namespace std;

#define MAX 50
#define endl "\n"

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int board[MAX][MAX];
int N, M, Answer = 0;

pair<int, int> start_point;
bool visit[MAX][MAX];
int dir;

void init()
{
    cin >> N >> M;
    cin >> start_point.first >> start_point.second >> dir;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
}

void DFS(int nDx, int nDy, int dir)
{
    // 현재 위치를 청소 한다.
    // 만약 후진한 경우 청소한 칸이므로 청소한 갯수를 포함하지 않는다.
    if (visit[nDx][nDy] == false)
    {
        visit[nDx][nDy] = true;
        Answer++;
    }

    bool find = false;

    for (int i = 1; i < 5; i++)
    {
        // 왼쪽 방향을 확인한다.
        int n_dir = dir - i >= 0 ? dir - i : dir - i + 4;
        int nx = nDx + dx[n_dir];
        int ny = nDy + dy[n_dir];

        // 만약 왼쪽 방향에 청소할 곳이 있다면 그 방향으로 회전한 후 한 칸을 전진한다.
        if (board[nx][ny] == 0 && visit[nx][ny] == false)
        {
            find = true;
            DFS(nx, ny, n_dir);
            break;
        }
    }

    // 네 방향 모두 청소가 되어있거나 벽인 경우 한 칸 후진한다.
    if (!find)
    {
        int bx = nDx - dx[dir];
        int by = nDy - dy[dir];

        // 만약 후진할 수 없다면 종료한다.
        if (board[bx][by] == 1)
            return;
        DFS(bx, by, dir);
    }
}

void start()
{
    init();
    DFS(start_point.first, start_point.second, dir);
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    start();
    cout << Answer << endl;

    return 0;
}
