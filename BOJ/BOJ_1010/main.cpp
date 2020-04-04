// https://www.acmicpc.net/problem/1010
// 다리 놓기

// DP[i][j] = DP[i][j-1] + DP[i-1][j-1]

#include <iostream>

using namespace std;

int N, M;
long long DP[31][31];
bool ck[30];

void init()
{
    cin >> N >> M;
}

int main()
{
    int tc;
    cin >> tc;

    for (int i = 1; i < 31; i++)
    {
        DP[1][i] = i;
    }

    for (int i = 2; i < 31; i++)
    {
        DP[i][i] = 1;
        for (int j = i + 1; j < 31; j++)
        {
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];
        }
    }

    for (int t = 0; t < tc; t++)
    {
        init();
        cout << DP[N][M] << endl;
    }
    return 0;
}