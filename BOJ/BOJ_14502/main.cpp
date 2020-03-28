#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 8
#define endl "\n"

using namespace std;

vector<pair<int, int>> virus, zeros;

int N, M, zeroCnt, maxZero, answer;
char board[MAX][MAX], tmp_board[MAX][MAX];
bool ck[MAX * MAX];
bool visit[MAX][MAX];

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
            if (board[i][j] == '2')
                virus.push_back(make_pair(i, j));
            else if (board[i][j] == '0')
                zeros.push_back(make_pair(i, j));
        }
    }
    zeroCnt = zeros.size();
}

void Copy_Board()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tmp_board[i][j] = board[i][j];
        }
    }
}

int Count_Zeros()
{
    int ret = 0;
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

void BFS(int x, int y)
{
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visit[x][y] = true;
    while (q.empty() == 0)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M)
            {
                if (visit[nx][ny] == false && tmp_board[nx][ny] == '0')
                {
                    tmp_board[nx][ny] = '2';
                    visit[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void Spread_Virus()
{
    int Cnt = 0;
    Copy_Board();
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < zeroCnt; i++)
    {
        if (Cnt == 3)
            break;
        if (ck[i] == true)
        {
            int x = zeros[i].first;
            int y = zeros[i].second;
            tmp_board[x][y] = 1;
            Cnt++;
        }
    }

    for (int i = 0; i < virus.size(); i++)
    {
        int x = virus[i].first;
        int y = virus[i].second;
        BFS(x, y);
    }

    answer = max(answer, Count_Zeros());
}

void solve(int num, int idx)
{
    if (num == 3)
    {
        Spread_Virus();
        return;
    }

    for (int i = idx; i < zeroCnt; i++)
    {
        if (ck[i] == true)
            continue;
        ck[i] = true;
        solve(num + 1, i);
        ck[i] = false;
    }
}

void start()
{
    init();
    solve(0, 0);
}

int main(void)
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    start();
    cout << answer << endl;

    return 0;
}