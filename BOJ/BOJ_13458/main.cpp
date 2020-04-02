#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int N, B, C;
vector<int> V;
long long ans = 0;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        V.push_back(num);
    }
    cin >> B >> C;
}

void solution()
{
    // 총감독관이 감독할 수 있는 범위.
    int i;
    for (i = 0; i < V.size(); i++)
    {
        V[i] -= B;
        ans++;
    }

    // 부감독관이 감독할 수 있는 범위.
    // 만약 수험생들이 모두 커버되어 있다면 pass.
    for (i = 0; i < V.size(); i++)
    {
        if (V[i] > 0)
        {
            ans += V[i] / C;

            // 나머지가 존재한다면 한명의 부감독관이 더 필요하다.
            if (V[i] % C != 0)
            {
                ans++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    init();
    solution();
    cout << ans << endl;

    return 0;
}
