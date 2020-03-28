#include <iostream>
using namespace std;

int price[4];
int dayOfMonth[13];

int minMonth[13];
int d[13];

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> price[i];
        }
        for (int i = 1; i < 13; i++)
        {
            cin >> dayOfMonth[i];
        }

        for (int i = 1; i < 13; i++)
        {
            minMonth[i] = min(price[0] * dayOfMonth[i], price[1]);
        }

        // d[N] => N번째 달의 누적된 최솟값.
        for (int i = 1; i < 13; i++)
        {
            d[i] = d[i - 1] + minMonth[i];
            if (i - 3 >= 0)
            {
                if (d[i] > d[i - 3] + price[2])
                {
                    d[i] = d[i - 3] + price[2];
                }
            }
        }

        if (d[12] > price[3])
            d[12] = price[3];

        cout << "#" << t + 1 << " " << d[12] << endl;
    }
}
