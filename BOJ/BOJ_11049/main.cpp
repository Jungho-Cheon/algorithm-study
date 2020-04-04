// https://www.acmicpc.net/problem/11049
// 행렬 곱셈 순서

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 500;
const int INF = 987654321;

int N;
pair<int, int> matrix[MAX];
int cache[MAX][MAX];

// left ~ right까지 드는 비용.
int minCalc(int left, int right)
{
    if (left == right)
        return 0;

    int &result = cache[left][right];
    if (result != -1)
        return result;

    result = INF;
    for (int i = left; i < right; i++)
    {
        result = min(result, minCalc(left, i) + minCalc(i + 1, right) + matrix[left].first * matrix[i].second * matrix[right].second);
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> matrix[i].first >> matrix[i].second;
    }

    memset(cache, -1, sizeof(cache));
    cout << minCalc(0, N - 1) << endl;
    return 0;
}