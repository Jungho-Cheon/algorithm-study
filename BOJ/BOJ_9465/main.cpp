// https://www.acmicpc.net/problem/9465
// 스티커

#include <iostream>
#include <algorithm>

#define endl "\n"
using namespace std;

int N;
int DP[2][100000];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void init()
{
    cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> DP[i][j];
        }
    }
}

void solution()
{
    int ans = 0;
    int tmp = 0;
    int l = 0;
    // 기준 좌표 (i, j)
    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
                DP[i][j] += max(DP[i + 1][j - 1], DP[i + 1][j - 2]);
            else if (i == 1)
                DP[i][j] += max(DP[i - 1][j - 1], DP[i - 1][j - 2]);
            ans = max(ans, DP[i][j]);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++)
    {
        init();
        solution();
    }
    return 0;
}