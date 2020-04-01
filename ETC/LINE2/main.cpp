#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cards[3];
bool visit[3];
vector<int> V;
int K, num;

void init()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> cards[i];
    }
    cin >> K;
    num = 0;

    sort(cards, cards + 3);
}

void solution(int cnt)
{
    if (cnt == 3)
    {
        num++;
        if (num == K)
        {
            for (int n : V)
            {
                cout << n << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        V.push_back(cards[i]);
        solution(cnt + 1);
        V.pop_back();
        visit[i] = false;
    }
}

int main()
{
    init();
    solution(0);

    return 0;
}
