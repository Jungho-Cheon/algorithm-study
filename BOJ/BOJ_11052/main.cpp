// https://www.acmicpc.net/problem/11052
// 카드 N장을 가장 비싸게 사는 문제.
// 1) 마지막에 카드 1장을 샀을때 최대 비용은 N-1장까지의 최대값과 1장의 가격을 더한 것이다.
// 2) 마지막에 카드 2장을 샀을때 최대 비용은 N-2장까지의 최대값과 2장의 가격을 더한 것이다.
// N) 마지막에 카드 N장을 샀을 때 최대 비용은 N-N장까지의 최댓값과 N장의 가격을 더한 것이다.

// 점화식
// DP[0] = arr[0] = 0
// 1 <= i <= N, 1 <= j <= i
// DP[i] = max(DP[i], DP[i-j] + arr[j])

#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int p[1000];
int DP[1000];

void init()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> p[i];
    }
}

void solution()
{
    p[0] = DP[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            DP[i] = max(DP[i], DP[i - j] + p[j]);
        }
    }
}

int main()
{
    init();
    solution();
    cout << DP[N] << endl;
    return 0;
}