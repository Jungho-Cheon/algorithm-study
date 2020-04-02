// https://www.acmicpc.net/problem/1520

#include <iostream>

#define endl "\n"
#define MAX 500
using namespace std;

int N, M, ans;
int board[MAX][MAX];
int DP[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            DP[i][j] = -1;
        }
    }
    ans = 0;
}
// (0, 0)을 시작으로 (N-1, M-1)에 도착하는 경로를 찾았을 때,
// 재귀적으로 복귀하면서 모두 1을 채운다. 만약 for문에서 여러 갈래로 나뉠경우 그 가지 수 만큼 1이 복귀되어 더해진다.
// 만약 경로를 찾는 도중 이미 발견한 경로를 마주칠 경우 더 이상 탐색하지 않고 DP값을 더한다.
int solution(int x, int y)
{
    if (x == N - 1 && y == M - 1)
    {
        return 1;
    }

    if (DP[x][y] == -1)
    {
        DP[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || N <= nx || ny < 0 || M <= ny)
                continue;
            if (board[nx][ny] < board[x][y])
            {
                DP[x][y] += solution(nx, ny);
            }
        }
    }

    return DP[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    cout << solution(0, 0) << endl;
    return 0;
}