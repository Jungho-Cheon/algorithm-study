// https://www.acmicpc.net/problem/11057

#include <iostream>
#include <cstring>
using namespace std;

int N;
int DP[1001][10];

int main()
{

    for (int i = 0; i < 10; i++)
    {
        DP[0][i] = 1;
    }
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k < 10; k++)
            {
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % 10007;
            }
        }
    }

    cout << DP[N][0] << endl;

    return 0;
}