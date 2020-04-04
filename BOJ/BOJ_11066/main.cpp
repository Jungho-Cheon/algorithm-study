// https://www.acmicpc.net/problem/11066
// 파일 합치기

// 연속된 파일들의 부분합을 최소로 만드는 문제.
// 부분합의 크기를 구하기 위해 누적합을 구한다.
// 만약 i ~ j의 부분합을 구하기 위해서는 S[i + j] - S[i - 1]을 구하면 된다.

#include <iostream>
#include <algorithm>

#define endl "\n"
using namespace std;
int N;
int arr[501];
int S[501];
int DP[501][501];

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        S[i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        S[i] += S[i - 1] + arr[i];
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            DP[i][j] = 0;
        }
    }
}

void solution()
{
    // 부분 파일 길이
    for (int i = 1; i < N; i++)
    {
        // 시작점
        for (int j = 1; j <= N - i; j++)
        {

            int tmp = 1e9;
            if (i == 1)
                tmp = 0;
            for (int k = 0; k < i; k++)
            {
                tmp = min(tmp, DP[j][j + k] + DP[j + k + 1][j + i]);
            }
            DP[j][j + i] = tmp + S[j + i] - S[j - 1];
        }
    }
    cout << DP[1][N] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        init();
        solution();
    }
    return 0;
}
