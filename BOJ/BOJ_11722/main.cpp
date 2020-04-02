// https://www.acmicpc.net/problem/11722

#include <iostream>

using namespace std;

int N;
int arr[1000];
int ck[1000];

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        ck[i] = 1;
    }
}

void solution()
{
    int ret = -1;
    for (int i = 0; i < N; i++)
    {
        int max_val = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                max_val = (max_val < ck[j]) ? ck[j] : max_val;
            }
        }
        ck[i] += max_val;
        ret = (ret < ck[i]) ? ck[i] : ret;
    }

    cout << ret << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution();

    return 0;
}