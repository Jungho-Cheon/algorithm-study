#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, C, MAX, ans = 0;
int board[8][8];
bool visit[8][8];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init()
{
    cin >> N >> C;
    MAX = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            MAX = max(MAX, board[i][j]);
        }
    }
}

void solution(int depth, int x, int y)
{
    visit[x][y] = true;
    bool is_find = false;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || N <= nx || ny < 0 || N <= ny)
            continue;
        if (visit[nx][ny])
            continue;
        // 주변에 자신보다 낮은 위치가 존재한 경우 진행.
        if (board[nx][ny] < board[x][y])
        {
            is_find = true;

            solution(depth + 1, nx, ny);
        }
        // 만약 자신보다 크지만 아직 C를 사용하지 않는 경우 사용 후 진행.
        else if (board[nx][ny] >= board[x][y] && C != -1)
        {
            if (board[nx][ny] - C < board[x][y])
            {
                is_find = true;

                int Ctmp = C;
                int tmp = board[nx][ny];

                // C를 한번만 사용하기 위해 -1값을 주었다.
                C = -1;
                board[nx][ny] = board[x][y] - 1;

                solution(depth + 1, nx, ny);

                // 다음 탐색에서 영향을 주지 않기 위해 복구한다.
                board[nx][ny] = tmp;
                C = Ctmp;
            }
        }
    }
    visit[x][y] = false;

    // 더 이상 진행할 수 없는경우 최댓값을 갱신한 후 종료.
    if (!is_find)
    {
        ans = max(ans, depth);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 1; t < tc + 1; t++)
    {
        init();
        // 가장 높은 값을 가진 좌표에서 DFS를 수행한다.
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == MAX)
                {
                    solution(1, i, j);
                }
            }
        }

        cout << "#" << t << " " << ans << endl;
        ans = 0;
    }

    return 0;
}