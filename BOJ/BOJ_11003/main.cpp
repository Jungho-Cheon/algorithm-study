// https://www.acmicpc.net/problem/11003
// 최솟값 찾기
// 슬라이딩 윈도우

// 최솟값의 인덱스는 현재 인덱스에서 L이상 차이가 나면 안된다.
// 현재 인덱스의 값보다 큰값들이 dq에 존재하지 않게 하기 위해 매번 큰값들을 pop_back 해준다.

#include <iostream>
#include <deque>

#define endl "\n"
#define MAX 5000000
using namespace std;

int N, L;
int arr[MAX];
deque<pair<int, int>> dq; // value, idx

void init()
{
    cin >> N >> L;
}

void solution()
{
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        // 만약 dq의 첫번째 값의 인덱스가 현재 인덱스 - L보다 작거나 같을경우 pop_front()한다.
        if (!dq.empty() && dq.front().second <= i - L)
        {
            dq.pop_front();
        }
        // 현재 값보다 큰 값들을 모두 pop_back하여
        // dq의 값들이 항상 오름차순을 유지하도록 한다.
        while (!dq.empty() && dq.back().first > arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(make_pair(arr[i], i));
        cout << dq.front().first << " ";
    }
    cout << endl;
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