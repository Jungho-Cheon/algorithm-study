// DP[K][N] : K개를 더해서 N이 나온경우의 수.
#include <iostream>

using namespace std;
long long DP[201][201];

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= N; i++)
    {
        DP[1][i] = 1;
    }
    for (int i = 2; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % 1000000000;
            }
        }
    }
    cout << DP[K][N] % 1000000000 << endl;
    return 0;
}