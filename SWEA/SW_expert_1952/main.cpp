#include <iostream>
#include <vector>
#define endl "\n"
#define MAX 12

using namespace std;

int price[4];
int month[MAX];
int tmp_month[MAX];
int Answer;
int day_count = 0;

vector<int> V;

void Init()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < MAX; i++)
    {
        cin >> month[i];
        tmp_month[i] = month[i];
        day_count += month[i];
    }
    // 일년권 선택
    Answer = price[3];
    // cout << day_count << ", " << Answer << endl;
}

void Solution(int count)
{
    if (count == 0)
    {
        // cout << "V Size : " << V.size() << endl;
        int temp = 0;
        for (int i = 0; i < V.size(); i++)
            temp += V[i];
        Answer = Answer < temp ? Answer : temp;
        return;
    }

    // 한달 : 하루권 * 일 수 or 한달권
    // 세달 : 한달권 * 3 or 세달 권
    for (int i = 0; i < 12; i++)
    {
        if (i < 10)
        {
            if (month[i] != 0 && month[i + 1] != 0 && month[i + 2] != 0)
            {
                // 세달권 선택
                month[i] = 0;
                month[i + 1] = 0;
                month[i + 2] = 0;
                V.push_back(price[2]);
                Solution(count - (tmp_month[i] + tmp_month[i + 1] + tmp_month[i + 2]));
                V.pop_back();
                month[i] = tmp_month[i];
                month[i + 1] = tmp_month[i + 1];
                month[i + 2] = tmp_month[i + 2];
            }
        }

        if (month[i] != 0)
        {
            if (month[i] * price[0] > price[1])
            {
                // 한달권 선택
                month[i] = 0;
                V.push_back(price[1]);
                Solution(count - tmp_month[i]);
                V.pop_back();
                month[i] = tmp_month[i];
            }
            else
            {
                // 하루권 선택
                month[i] = 0;
                V.push_back(tmp_month[i] * price[0]);
                Solution(count - tmp_month[i]);
                V.pop_back();
                month[i] = tmp_month[i];
            }
        }
    }
}

void Solve()
{
    int TestCase;
    cin >> TestCase;
    for (int i = 0; i < TestCase; i++)
    {
        Init();
        Solution(day_count);
        cout << "Answer : " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}