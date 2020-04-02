// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cstring>

using namespace std;

int col[15];
int ans = 0, N;

bool isValid(int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        if (col[i] == c)
            return false;
        if (abs(i - r) == abs(col[i] - c))
        {
            //cout << i << r << col[i] << c << endl;
            return false;
        }
    }
    return true;
}

void find(int r, int c)
{
    if (r == N - 1)
    {
        ans++;
        return;
    }

    col[r] = c;

    for (int i = 0; i < N; i++)
    {
        if (isValid(r + 1, i))
            find(r + 1, i);
    }

    col[r] = -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            col[j] = -1;
        }

        find(0, i);
    }

    cout << ans << endl;

    return 0;
}