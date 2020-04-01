#include <iostream>

#define endl "\n"
using namespace std;

int N, K;

int people[1000];

void init()
{
    cin >> N >> K;
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        int group;
        cin >> group;
        people[idx++] = group;
    }
}

void solution()
{
    int time = 0;
    int len[10] = {
        0,
    };

    // 사람들을 줄세운다.
    for (int a : people)
    {
        int min_k = 1e9;
        int min_idx = 0;

        // 줄이 가장 짧은 매표소 인덱스 찾기.
        for (int i = 0; i < K; i++)
        {
            if (len[i] < min_k)
            {
                min_k = len[i];
                min_idx = i;
            }
        }

        len[min_idx] += a;
    }

    // 가장 길이가 긴 줄을 찾는다.
    int ret = 0;
    for (int i = 0; i < K; i++)
    {
        ret = (ret > len[i]) ? ret : len[i];
    }
    cout << ret << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    init();
    solution();

    return 0;
}