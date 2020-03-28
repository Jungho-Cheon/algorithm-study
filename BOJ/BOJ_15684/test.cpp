#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
int arr[] = {2, 5, 7, 9};
bool ck[3];

void permutation(int idx, int depth)
{
    if (depth == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << V[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (ck[i])
            continue;
        V.push_back(arr[i]);
        ck[i] = true;
        permutation(i, depth + 1);
        ck[i] = false;
        V.pop_back();
    }
}

int main()
{

    permutation(0, 0);

    return 0;
}