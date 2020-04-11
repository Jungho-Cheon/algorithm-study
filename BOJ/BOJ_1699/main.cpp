// https://www.acmicpc.net/problem/1699
// 제곱수의 합

#include <iostream>

using namespace std;

int DP[100001];

void solution(int N)
{
    for (int i = 1; i <= N; i++)
    {
        DP[i] = i;
        for (int j = 2; j * j <= i; j++)
        {
            DP[i] = min(DP[i], DP[i - (j * j)] + 1);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    solution(N);
    cout << DP[N] << endl;

    return 0;
}