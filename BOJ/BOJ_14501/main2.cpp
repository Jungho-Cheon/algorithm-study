// https://www.acmicpc.net/problem/14501
// 풀이 2 : DP

// DP[N]을 N일까지 얻는 이익이라고 생각하면.
// DP[i] = max(DP[i], DP[j] + arr[i])
// 0 < j < i

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[2][20]; // 0 : t, 1 : p
int DP[20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[0][i] >> arr[1][i];
        DP[i] = arr[1][i];
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i - j >= arr[0][j])
            {
                DP[i] = max(DP[i], DP[j] + arr[1][i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i + arr[0][i] <= N + 1)
            ans = max(ans, DP[i]);
    }
    cout << ans << endl;

    return 0;
}