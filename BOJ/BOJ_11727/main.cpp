// https://www.acmicpc.net/problem/11727

// 점화식
// DP[0] = 1, DP[1] = 3
// DP[i] = DP[i-1] + (DP[i-2] * 2) (i > 2)

#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int DP[1000];
    DP[0] = 1;
    DP[1] = 3;

    if (N < 2)
    {
        cout << DP[N - 1] << endl;
        return 0;
    }
    for (int i = 2; i < N; i++)
    {
        DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;
    }
    cout << DP[N - 1] << endl;

    return 0;
}