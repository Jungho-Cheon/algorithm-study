// https://www.acmicpc.net/problem/2294
// 동전 2

#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 10001
using namespace std;

int N, K;
int coin_value[101], DP[MAX];

void solution()
{
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= K; i++)
    {
        DP[i] = MAX;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = coin_value[i]; j <= K; j++)
        {
            DP[j] = min(DP[j], DP[j - coin_value[i]] + 1);
        }
    }
    int ans = (DP[K] == MAX) ? -1 : DP[K];
    cout << ans << endl;
}

int main()
{
    cin >> N >> K;
    if (N < 1 || 100 < N || K < 1 || MAX <= K)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> coin_value[i];
    }

    solution();

    return 0;
}