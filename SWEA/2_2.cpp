// 주어진 2차원 char배열에서 길이가 가장 긴 회문 찾기
// 가로, 세로 모두 찾아야한다.
//
// - 최적화 tip
// * 길이가 가장 긴 회문을 먼저 탐색한다.
// * 회문을 찾았을 경우 그보다 길이가 작은 구역은 검사하지 않는다.
// * 이 후 다른 회문을 탐색할 때도 현재 찾은 회문의 길이보다 길이가 짧은 회문을 찾지 않는다.

#include <iostream>

#define endl "\n"
#define MAX 100
using namespace std;

char board[MAX][MAX];

bool isPalindrome(char *p, int len)
{
    for (int i = 0; i < (len + 1) / 2; i++)
    {
        if (*(p + i) != *(p + len - 1 - i))
        {
            return false;
        }
    }
    return true;
}

int getMaxPalindrome(char board[][100])
{
    int max = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 100 - j; k > max; k--)
            {
                if (isPalindrome(&board[i][j], k))
                {
                    max = (max > k) ? max : k;
                    break;
                }
            }
        }
    }
    return max;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int ans = 0;
    int ans_2 = 0;
    for (int tc = 1; tc <= 10; tc++, ans = 0, ans_2 = 0)
    {
        int n;
        cin >> n;

        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                cin >> board[i][j];
            }
        }

        ans = getMaxPalindrome(board);

        // 세로 방향을 탐색하기 위해 행과 열을 swap한다.
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (i < j)
                {
                    char t = board[i][j];
                    board[i][j] = board[j][i];
                    board[j][i] = t;
                }
            }
        }
        ans_2 = getMaxPalindrome(board);
        ans = (ans > ans_2) ? ans : ans_2;

        cout << "#" << tc << " " << ans << endl;
    }

    return 0;
}