// https://www.acmicpc.net/submit/2293
// 동전 1

// N원을 만드는 경우의 수는 N-1원을 만드는 경우에 수에 N원짜리 동전을 추가하는 것과 같다.
// N원짜리 동전 이상의 수를 만들때 경우의 수를 추가시킨다.

// K  : 0 1 2 3 4 5 6 7 8 9 10
// DP : 1 0 0 0 0 0 0 0 0 0 0  (초기화)
// DP : 1(1)1 1 1 1 1 1 1 1 1  (coins[0] => 1원짜리 동전)
// DP : 1 1(2)2 3 3 4 4 5 5 6  (coins[1] => 2원짜리 동전)
// DP : 1 1 2 2 3(4)5 6 7 8 10 (coins[2] => 5원짜리 동전)

#include <iostream>

using namespace std;

int main()
{
    int i, j, N, K;
    int DP[10001] = {

        0,
    };
    cin >> N >> K;

    int coins[N];
    for (i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    DP[0] = 1;
    for (i = 0; i < N; i++)
    {
        for (j = coins[i]; j <= K; j++)
        {
            if (j - coins[i] >= 0)
            {
                DP[j] += DP[j - coins[i]];
            }
        }
    }
    cout << DP[K] << endl;

    return 0;
}