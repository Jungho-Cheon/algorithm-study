// https://www.acmicpc.net/problem/14501
// 풀이 1 : 완전 탐색
// 경우의 수가 적기 때문에 가능하다.
// 날짜의 조합을 탐색하며 선택이 가능한 모든 경우의 P의 합을 갱신한다.

#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;

int N, ans;
vector<pair<int, int>> V;
vector<pair<int, int>> sel;
bool ck[20];

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    ans = 0;
}

bool isValid(int idx)
{
    if (V[idx].first + idx > N)
        return false;

    for (int i = 0; i < sel.size(); i++)
    {
        if (sel[i].first <= idx && idx <= sel[i].second)
            return false;

        if (sel[i].first <= V[idx].first + idx - 1 && V[idx].first + idx - 1 <= sel[i].second)
        {
            return false;
        }
    }
    return true;
}

void solution(int cnt, int idx)
{
    int tmp = 0;
    for (int i = 0; i < V.size(); i++)
    {
        if (ck[i])
            tmp += V[i].second;
    }
    ans = (ans < tmp) ? tmp : ans;

    if (cnt == N)
        return;

    for (int i = idx; i < V.size(); i++)
    {
        if (ck[i])
            continue;

        if (!isValid(i))
            continue;

        ck[i] = true;
        sel.push_back(make_pair(i, V[i].first + i - 1));
        solution(cnt + 1, i);
        sel.pop_back();
        ck[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution(0, 0);
    cout << ans << endl;

    return 0;
}