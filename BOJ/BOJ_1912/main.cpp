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