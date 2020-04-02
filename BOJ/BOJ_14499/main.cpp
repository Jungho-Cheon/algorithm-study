// https://www.acmicpc.net/problem/14499

#include <iostream>
#include <queue>

#define endl "\n"
using namespace std;

int N, M, x, y, K;
int board[20][20];
queue<int> orders;
int dice[7];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void init()
{
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int order;
        cin >> order;
        orders.push(order);
    }
}

void rotate(int dir)
{
    // 동쪽, 서쪽으로 굴릴 경우
    // 2, 5 : 바뀌지 않음
    // 4 <-> 1 <-> 3 <-> 6 <-> 4 rotate

    // 북쪽, 남쪽으로 굴릴 경우
    // 4, 3 : 바뀌지 않음
    // 6 <-> 5 <-> 1 <-> 2 <-> 6 rotate
    int tmp;

    if (dir == 0)
    {
        // 동쪽으로 굴림
        tmp = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = dice[1];
        dice[1] = tmp;
    }
    else if (dir == 1)
    {
        // 서쪽으로 굴림
        tmp = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = tmp;
    }
    else if (dir == 2)
    {
        // 북쪽으로 굴림
        tmp = dice[6];
        dice[6] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = tmp;
    }
    else if (dir == 3)
    {
        // 남쪽으로 굴림
        tmp = dice[6];
        dice[6] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = tmp;
    }
}

void solution(int cx, int cy)
{
    while (orders.empty() == 0)
    {
        // 동쪽 : 0 , 서쪽 : 1, 북쪽 : 2, 남쪽 : 3
        int dir = orders.front() - 1;
        //cout << "dir : " << dir << endl;
        orders.pop();

        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        // cout << nx << ", " << ny << endl;

        if (nx < 0 || N <= nx || ny < 0 || M <= ny)
            continue;

        cx = nx;
        cy = ny;

        rotate(dir);

        if (board[nx][ny] == 0)
        {
            board[nx][ny] = dice[6];
        }
        else if (board[nx][ny] > 0)
        {
            dice[6] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << dice[1] << endl;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    init();
    solution(x, y);

    return 0;
}
