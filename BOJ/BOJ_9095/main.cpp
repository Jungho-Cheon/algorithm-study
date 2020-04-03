// https://www.acmicpc.net/problem/9095

// 1, 2, 3 더하기
// 정수 N을 1, 2, 3의 합으로 나타낼 수 있는 경우의 수를 구하는 문제
// 수를 중복해서 사용해도 된다
// 1. 중복 조합을 이용한 풀이
// 2. DP

// 정수 N을 합으로 표시하는 방법의 수는
// DP[N] = DP[N-1] + DP[N-2] + DP[N-3]

#include <iostream>

using namespace std;

int main()
{
    int tc, N;
    int DP[11] = {
        0,
    };

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for (int i = 4; i < 11; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> N;
        cout << DP[N] << endl;
    }
    return 0;
}