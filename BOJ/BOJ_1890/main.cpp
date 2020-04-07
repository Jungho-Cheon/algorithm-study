#include <iostream>

using namespace std;

typedef long long ll;

int N;
int board[100][100];
ll visit[100][100];

int dx[] = {1, 0};
int dy[] = {0, 1};

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            visit[i][j] = -1;
        }
    }
}

ll solution(int x, int y)
{
    // 종착지에 도착한 경우
    if (x == N - 1 && y == N - 1)
        return 1;

    ll &result = visit[x][y];

    if (result != -1)
        return result;

    result = 0;
    if (y != N - 1 && y + board[x][y] < N)
        result += solution(x, y + board[x][y]);
    if (x != N - 1 && x + board[x][y] < N)
        result += solution(x + board[x][y], y);

    return result;
}

int main()
{
    init();
    cout << solution(0, 0) << endl;

    return 0;
}