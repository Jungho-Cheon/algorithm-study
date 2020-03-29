#include <iostream>

#define endl "\n"
using namespace std;

int arr[5] = {-1, -1, -1, -1, -1};

void print_()
{
    for (int i = 1; i < 5; i++)
        cout << arr[i];
    cout << endl;
}

void back_tracking(int depth, int val, int ones, int zeros)
{
    arr[depth] = val;

    if (zeros == 3 && depth == 3)
        return;

    if (depth == 4)
    {
        if (ones == 2)
        {
            print_();
        }
        return;
    }

    back_tracking(depth + 1, 0, ones, zeros + 1);
    back_tracking(depth + 1, 1, ones + 1, zeros);
}

int main()
{
    ios::sync_with_stdio(false);

    back_tracking(0, 0, 0, 0);

    return 0;
}