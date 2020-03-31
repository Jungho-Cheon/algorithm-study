#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"
using namespace std;

int N, ans;
int board[10][10];
pair<int, int> people[10];
pair<int, int> stairs[2];

vector<pair<int, int>> P;
vector<pair<int, int>> P2;

int p_num = 0;
bool check[10];

void init()
{
    cin >> N;
    ans = 1e9;
    p_num = 0;
    int s_idx = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                // 사람인 경우
                people[p_num++] = make_pair(i, j);
            }
            else if (board[i][j] > 1)
            {
                // 계단인 경우
                stairs[s_idx++] = make_pair(i, j);
            }
        }
    }
}

// 주어진 P1, P2에 대해 시간의 흐름에 따라 Q1, Q2의 시뮬레이션을 진행한다.
// 이 후 최솟값을 ans에 갱신한다.
void simulation()
{
    // P, P2가 갱신된 상태.
    queue<int> Q1, Q2;

    // P는 조합을 구하기 위해 사용 중이므로 원본을 잃지 않기위해 복사해서 사용한다.
    vector<pair<int, int>> P1;
    for (int i = 0; i < P.size(); i++)
    {
        P1.push_back(P[i]);
    }

    // P1, P2에 담겨있는 좌표에 대해 각각 거리를 담는 배열을 만든다.
    vector<int> p1_dist;
    vector<int> p2_dist;

    // 특정 사람이 대기 중이였는지 알기위한 flag
    bool p1_wait[10] = {
        0,
    };
    bool p2_wait[10] = {
        0,
    };

    // 각각의 사람들과 계단과의 거리를 구한다.
    for (int i = 0; i < P1.size(); i++)
    {
        p1_dist.push_back(abs(stairs[0].first - P1[i].first) + abs(stairs[0].second - P1[i].second));
    }
    for (int i = 0; i < P2.size(); i++)
    {
        p2_dist.push_back(abs(stairs[1].first - P2[i].first) + abs(stairs[1].second - P2[i].second));
    }

    // 계단과 가까운 사람부터 접근하므로 거리순으로 정렬한다.
    sort(p1_dist.begin(), p1_dist.end());
    sort(p2_dist.begin(), p2_dist.end());

    int time = 0;
    int p1_idx = 0, p2_idx = 0;
    while (Q1.empty() == 0 || Q2.empty() == 0 || p1_idx < p1_dist.size() || p2_idx < p2_dist.size())
    {
        // 최적화(1) : 최솟값을 구하는 경우이기 때문에 현재 시간이 ans보다 커질경우 더 이상 계산하지 않는다.
        if (ans + 1 < time)
            return;

        // Q의 첫번째 값과 현재 진행시간을 비교하여 같은 값을 갖는 사람들을 완료(pop)시킨다.
        while (1)
        {
            if (Q1.empty() == 1)
                break;
            else
            {
                if (Q1.front() == time)
                    Q1.pop();
                else
                    break;
            }
        }

        while (1)
        {
            if (Q2.empty() == 1)
                break;
            else
            {
                if (Q2.front() == time)
                    Q2.pop();
                else
                    break;
            }
        }

        // 아직 계단에 내려가지 못한 사람이 존재할 경우에 대한 처리 (index 오류를 방지하기 위함.)
        if (p1_idx < p1_dist.size())
        {
            int wait_ = 0;
            // 대기 없이 계단을 내려가는 사람들은 도착 이후 1분을 더 기다린다.
            if (!p1_wait[p1_idx])
                wait_ = 1;
            while (Q1.size() < 3)
            {
                if (p1_dist[p1_idx] == time)
                {
                    Q1.push(board[stairs[0].first][stairs[0].second] + p1_dist[p1_idx] + wait_);
                    p1_idx++;
                    if (p1_dist.size() <= p1_idx)
                        break;
                }
                else
                    break;
            }
            // 도착은 했지만 대기하는 사람들에 대해 시간을 +1 해준다.
            if (p1_idx < p1_dist.size())
            {
                if (p1_dist[p1_idx] == time)
                {
                    for (int i = p1_idx; i < p1_dist.size(); i++)
                    {
                        if (p1_dist[i] == time)
                        {
                            p1_wait[i] = true;
                            p1_dist[i]++;
                        }
                        else
                            break;
                    }
                }
            }
        }

        //cout << "p1 pass" << endl;

        if (p2_idx < p2_dist.size())
        {
            int wait_ = 0;
            if (!p2_wait[p2_idx])
                wait_ = 1;

            while (Q2.size() < 3)
            {
                if (p2_dist[p2_idx] == time)
                {
                    Q2.push(board[stairs[1].first][stairs[1].second] + p2_dist[p2_idx] + wait_);
                    p2_idx++;

                    if (p2_dist.size() <= p2_idx)
                        break;
                }
                else
                    break;
            }
            if (p2_idx < p2_dist.size())
            {
                if (p2_dist[p2_idx] == time)
                {
                    for (int i = p2_idx; i < p2_dist.size(); i++)
                    {
                        if (p2_dist[i] == time)
                        {
                            p2_wait[i] = true;
                            p2_dist[i]++;
                        }
                        else
                            break;
                    }
                }
            }
        }
        time++;
    }

    time--;
    ans = (time < ans) ? time : ans;
}

// 모든 사람들이 계단 1로 가는 경우와 2로가는 경우를 모두 구해야 한다.
// 크기 1~10 의 조합 : 나머지

void solution(int idx)
{
    for (int i = 0; i < p_num; i++)
    {
        if (!check[i])
            P2.push_back(people[i]);
    }

    // simulation()의 while문 종료조건이 모든 vector들이 비어있을 경우이므로 따로 초기화 하지 않는다.
    simulation();

    while (P2.empty() == 0)
        P2.pop_back();

    if (idx == 10)
    {
        return;
    }

    for (int i = idx; i < p_num; i++)
    {
        if (check[i])
            continue;
        check[i] = true;
        P.push_back(people[i]);
        solution(i);
        P.pop_back();
        check[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int t = 1; t < tc + 1; t++)
    {
        init();
        solution(0);
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}