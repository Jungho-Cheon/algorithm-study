#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

#define endl "\n"
using namespace std;

int N, K, L, dir;
vector<pair<int, int>> apple;
deque<pair<int, int>> snake;

bool appleCheck[100];

// 북, 동, 남, 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

typedef struct rotate_into
{
    int time;
    char direction;
} rotate_info;

queue<rotate_info> R;

// bool compare(const rotate_info &a, const rotate_info &b)
// {
//     return a.time < b.time;
// }

void init()
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        apple.push_back(make_pair(x - 1, y - 1));
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        rotate_info r;
        r.time = x;
        r.direction = c;
        R.push(r);
    }

    // sort(R.begin(), R.end(), compare);

    // cout << "dir check : " << endl;
    // for (int i = 0; i < R.size(); i++)
    // {
    //     cout << R[i].time << ", " << R[i].direction << endl;
    // }

    // 뱀의 초기 좌표, 길이는 snake.size() 이용
    snake.push_back(make_pair(0, 0));
    // 초기 방향 오른쪽.
    dir = 1;
}

bool move()
{
    // 뱀이 움직일 다음 좌표.
    int nx, ny;
    nx = snake[0].first + dx[dir];
    ny = snake[0].second + dy[dir];

    // 벽에 부딛혔을 경우와 자신의 몸에 부딛혔을 경우 false를 반환한다.
    if (nx < 0 || N <= nx || ny < 0 || N <= ny)
        return false;

    for (auto p : snake)
    {
        if (p.first == nx && p.second == ny)
            return false;
    }

    // 움직인 경로에 사과가 있는 경우
    bool eatApple = false;
    for (int i = 0; i < apple.size(); i++)
    {
        if (appleCheck[i])
            continue;
        if (apple[i].first == nx && apple[i].second == ny)
        {
            eatApple = true;
            appleCheck[i] = true;
        }
    }

    snake.push_front(make_pair(nx, ny));
    // 사과를 먹지 않은 경우 snake의 뒤를 pop하여 길이를 유지한다.
    if (!eatApple)
        snake.pop_back();

    return true;
}

// 뱀의 초기 방향은 오른쪽이다.
void solution()
{
    int time = 1;
    while (1)
    {
        if (!move())
            break;

        if (R.front().time == time)
        {
            if (R.front().direction == 'D')
            {
                dir = (dir + 1) % 4;
            }
            else if (R.front().direction == 'L')
            {
                dir = (dir + 3) % 4;
            }
            R.pop();
        }
        time++;
    }
    cout << time << endl;
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