#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int N, i;
    cin >> N;

    ll ans = 0;
    ll arr[N];
    ll dp[N];

    for (i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    ans = dp[0];

    for (i = 1; i < N; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(dp[i], ans);
    }

    cout << ans << endl;

    return 0;
}

//  - input
// 10
// 2 1 -4 3 4 -4 6 5 -5 1
// - output
// 14

//  - input
// 10
// 10 -4 3 1 5 6 -35 12 21 -1
// - output
// 33