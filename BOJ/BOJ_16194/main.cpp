// https://www.acmicpc.net/problem/16194
// 마지막에 1개를 살 때 최소 가격은 (N-1개를 살 때 최소 가격 + 카드 1개의 가격)
// 마지막에 2개를 살 때 최소 가격은 (N-2개를 살 때 최소 가격 + 카드 2개의 가격)

// 점화식
// DP[i] = min(DP[i], DP[i-j] + arr[j])
// - 최솟값을 구하는 문제이므로 DP배열을 충분히 큰수들로 초기화해야한다.

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1000];
int DP[1000];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        DP[i] = int(1e9);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            DP[i] = min(DP[i], DP[i - j] + arr[j]);
        }
    }

    cout << DP[N] << endl;

    return 0;
}