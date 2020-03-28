#include <iostream>

#define endl "\n"
using namespace std;

int board[10][10];
int N, M, C, res;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void init()
{
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
}

void getMaxPrice(int x, int y, int cnt, int sum, int price)
{
    if (sum > C)
        return;
    res = max(res, price);
    if (cnt == M)
        return;

    getMaxPrice(x, y + 1, cnt + 1, sum + board[x][y], price + board[x][y] * board[x][y]);
    getMaxPrice(x, y + 1, cnt + 1, sum, price);
}

int solve(int x, int y)
{
    res = 0;
    getMaxPrice(x, y, 0, 0, 0);
    int priceA = res;

    int priceB = 0;
    int j = y + M;
    for (int i = x; i < N; i++, j = 0)
    {
        for (; j <= N - M; j++)
        {
            res = 0;
            getMaxPrice(i, j, 0, 0, 0);
            priceB = max(priceB, res);
        }
    }

    return priceA + priceB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        init();
        int maxPrice = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= N - M; j++)
            {
                maxPrice = max(maxPrice, solve(i, j));
            }
        }
        cout << "#" << i + 1 << " " << maxPrice << endl;
    }
    return 0;
}