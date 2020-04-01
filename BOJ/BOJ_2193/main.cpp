#include <iostream>

#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    long long DP[2] = {1, 1};
    if (N <= 2)
    {
        cout << DP[N - 1] << endl;
        return 0;
    }

    for (int i = 0; i < N - 2; i++)
    {
        long long tmp = DP[0];
        DP[0] = DP[1];
        DP[1] = DP[0] + tmp;
    }

    cout << DP[1] << endl;
    return 0;
}