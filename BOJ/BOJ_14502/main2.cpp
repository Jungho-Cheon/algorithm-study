#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define endl "\n"
using namespace std;

typedef struct point
{
    int x, y;
} point;

int N, M, zero_num, ans;
char board[8][8];
point zeros[64];
bool visit[64];
vector<point> virus;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init()
{
    cin >> N >> M;
    ans = 0;
    zero_num = 0;

    int idx = 0;
    int v = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '0')
            {
                zeros[idx].x = i;
                zeros[idx++].y = j;
                zero_num++;
            }
            else if (board[i][j] == '2')
            {
                point P;
                P.x = i;
                P.y = j;
                virus.push_back(P);
            }
        }
    }
}

int spreadVirus(int tmp_board[][8])
{
    queue<point> Q;
    int ret = 0;
    bool visit[8][8] = {
        0,
    };

    for (point P : virus)
    {
        Q.push(P);
        visit[P.x][P.y] = true;
    }

    while (Q.empty() == 0)
    {
        int x = Q.front().x;
        int y = Q.front().y;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || N <= nx || ny < 0 || M <= ny)
                continue;
            if (tmp_board[nx][ny] == '0' && !visit[nx][ny])
            {
                tmp_board[nx][ny] = '2';
                visit[nx][ny] = true;

                point P;
                P.x = nx;
                P.y = ny;

                Q.push(P);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp_board[i][j] == '0')
                ret++;
        }
    }
    return ret;
}

void solution(int cnt, int idx)
{
    // '0'인 칸들에 대해 크기가 3인 조합을 구한다.
    if (cnt == 3)
    {
        int tmp_board[8][8];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                tmp_board[i][j] = board[i][j];
            }
        }

        ans = max(ans, spreadVirus(tmp_board));
        return;
    }

    for (int i = idx; i < zero_num; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        board[zeros[i].x][zeros[i].y] = '1';
        solution(cnt + 1, i);
        board[zeros[i].x][zeros[i].y] = '0';
        visit[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution(0, 0);

    cout << ans << endl;

    return 0;
}