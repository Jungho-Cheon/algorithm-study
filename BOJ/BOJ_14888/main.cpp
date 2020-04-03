// https://www.acmicpc.net/problem/14888
// 연산자 끼워 넣기

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int N, MAX, MIN;
vector<int> nums;
vector<int> oper_v;
int opers[12];
int oper_num;
bool ck[12];

void init()
{
    MAX = -1e9;
    MIN = 1e9;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    oper_num = 0;
    for (int i = 1; i < 5; i++)
    {
        int count;
        cin >> count;
        for (int j = 0; j < count; j++)
            opers[oper_num++] = i;
    }
}

int calc()
{
    // oper_v, nums 로 연산
    int n = nums[0];
    for (int i = 0; i < oper_num; i++)
    {
        if (oper_v[i] == 1)
        {
            n += nums[i + 1];
        }
        else if (oper_v[i] == 2)
        {
            n -= nums[i + 1];
        }
        else if (oper_v[i] == 3)
        {
            n *= nums[i + 1];
        }
        else if (oper_v[i] == 4)
        {
            n /= nums[i + 1];
        }
    }
    return n;
}

// 순열
void solution(int cnt)
{
    // 연산자 순열을 가지고 연산
    // 종료부
    if (cnt == oper_num)
    {
        int res = calc();
        MAX = max(MAX, res);
        MIN = min(MIN, res);
        return;
    }

    for (int i = 0; i < oper_num; i++)
    {
        if (ck[i])
            continue;
        ck[i] = true;
        oper_v.push_back(opers[i]);
        solution(cnt + 1);
        oper_v.pop_back();
        ck[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solution(0);

    cout << MAX << endl;
    cout << MIN << endl;

    return 0;
}