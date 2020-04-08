// https://www.acmicpc.net/problem/1004
// 어린 왕자

#include <iostream>

#define endl "\n"
using namespace std;

int start_point[2];
int end_point[2];
int N;
int ans = 0;

// 점과 원의 정보를 받아 포함관계인지 따진다.
bool check(int x, int xx, int y, int yy, int r)
{
    return (x - xx) * (x - xx) + (y - yy) * (y - yy) < r * r;
}

void solution()
{
    cin >> start_point[0] >> start_point[1];
    cin >> end_point[0] >> end_point[1];
    cin >> N;
    ans = 0;
    for (int i = 0; i < N; i++)
    {
        int x, y, r;
        cin >> x >> y >> r;

        // 둘중 하나만 원에 포함되어야 지나쳐야 하는 구간이 생긴다. (XOR 사용)
        ans += check(x, end_point[0], y, end_point[1], r) ^ check(x, start_point[0], y, start_point[1], r);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        solution();
    }

    return 0;
}