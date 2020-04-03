// https://www.acmicpc.net/problem/9465
// 스티커

// 상하좌우의 스티커를 고르지 못하는 특징에서 DP의 점화식을 구한다.
// 배열이 2행의 크기이므로 현재 좌표의 왼쪽 대각선에 위치한 칸과 그 칸의 왼쪽 칸 중 큰값을 더해 나가면 가장 큰 수를 구할 수 있다.

// 점화식
// DP[i][j] += max(DP[i+1][j-1], DP[i+1][j-2]) (i == 0)
// DP[i][j] += max(DP[i-1][j-1], DP[i-1][j-2]) (i == 1)

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

    DP[0][1] += DP[1][0];
    DP[1][1] += DP[0][0];

    // 기준 좌표 (i, j)
    for (int j = 2; j < N; j++)
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