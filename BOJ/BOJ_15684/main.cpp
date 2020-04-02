// https://www.acmicpc.net/problem/15684

#include <iostream>

#define endl "\n"
using namespace std;

int N, M, H;
bool ck[31][11];
// int right_side[11];
// int left_side[11];

int Answer = 987654321;

// i 번째 세로선의 결과가 i가 나오기 위해서
// 결과 i의 양옆 i - 1, i + 1에 연결되는 가로선이 존재해야한다.
// 혹은 가로선이 없다면 자기 자신에서 출발하면 된다.

bool check_all()
{
    for (int i = 1, cur; i <= N; i++)
    {
        int depth = 1;
        cur = i;
        while (depth <= H)
        {
            if (ck[depth][cur] == true)
            {
                cur++;
            }
            else if (ck[depth][cur - 1] == true)
            {
                cur--;
            }
            depth++;
        }
        if (cur != i)
        {
            return false;
        }
    }
    return true;
}

void solution(int count, int x, int y)
{
    if (count >= Answer)
        return;

    if (check_all())
    {
        Answer = count;
        return;
    }
    if (count == 3)
        return;

    for (int i = y; i <= H; i++, x = 1)
    {
        for (int j = x; j < N; j++)
        {
            if (ck[i][j] == true)
            {
                j++;
                continue;
            }

            ck[i][j] = true;
            solution(count + 1, j + 2, i);
            ck[i][j] = false;
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    // cin >> N >> M >> H;
    scanf("%d%d%d", &N, &M, &H);
    for (int i = 0, row, col; i < M; i++)
    {
        //cin >> row >> col;
        scanf("%d%d", &row, &col);
        ck[row][col] = true;
    }

    solution(0, 1, 1);

    if (Answer > 3)
        Answer = -1;

    // cout << Answer;

    printf("%d", Answer);
    return 0;
}