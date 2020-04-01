#include <iostream>

using namespace std;

int times[151];

int N, res = 0;
void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++)
        {
            times[i]++;
        }
    }

    for (int i = 0; i < 151; i++)
    {
        res = (res < times[i]) ? times[i] : res;
    }
}

int main()
{
    init();

    cout << res << endl;
    return 0;
}
