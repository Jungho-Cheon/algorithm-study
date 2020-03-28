#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 4
#define MAX_QUERYCOUNT 1000000

static int digits[N];
static int digits_c[10];

static int T;

static int querycount;

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;

typedef struct
{
    int strike;
    int ball;
} Result;

Result query(int guess[]);

Result comp(int A[], int B[])
{
    Result ret;
    ret.strike = 0;
    ret.ball = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (A[i] == B[j])
                ret.ball++;
        }
        if (A[i] == B[i])
        {
            ret.ball--;
            ret.strike++;
        }
    }
    return ret;
}

void InttoArray(int num, int ans[])
{

    int temp = num;
    if (num < 1000)
    {
        for (int j = 3; j > 0; j--)
        {
            ans[j] = temp % 10;
            temp /= 10;
        }
        ans[0] = 0;
    }
    else
    {
        for (int j = 3; j >= 0; j--)
        {
            ans[j] = temp % 10;
            temp /= 10;
        }
    }
}

bool diff(int arr[])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}

void doUserImplementation(int guess[])
{
    // 완성된 4자리 숫자에 대한 체크
    // 순차적으로 query를 줬을 때 나오는 strike와 ball을 가지고 순회하며 같은 값들을 갖는 숫자만 남긴다.
    bool ck[10000] = {
        0,
    };

    // 특정 1자리 숫자에 대한 체크 (계수)
    // 만약 strike와 ball 둘 다 0일 경우 모든 숫자가 포함되지 않으므로 해당 digit들을 제외시킨다.
    bool ck2[10] = {
        0,
    };

    // 무한 루프 방지를 위한 변수
    int full_count = 0;
    int cur_nums[4];
    int ans[4]; // int형을 자릿 수 별로 보관하기 위한 배열.

    Result res;
    while (full_count <= 1000000)
    {
        // 다음 query로 보낼 숫자를 찾기 위해 제외되지 않은 숫자중 첫 값을 찾는다.
        for (int i = 123; i < 9876; i++)
        {
            int tmp[4];
            // int => int[4]
            InttoArray(i, tmp);
            if (diff(tmp))
                continue;

            // 만약 존재하지 않는 digit이 검출되었다면 pass한다.
            if (ck2[tmp[0]] || ck2[tmp[1]] || ck2[tmp[2]] || ck2[tmp[3]])
                continue;

            // 첫번째로 가능한 값을 찾는다.
            if (!ck[i])
            {
                InttoArray(i, cur_nums);
                // query로 요청하여 새로운 strike값과 ball값을 받는다.
                res = query(cur_nums);

                // 만약 strike가 4인경우 정답이므로 guess의 값을 바꿔주고 종료한다.
                if (res.strike == 4 && res.ball == 0)
                {
                    guess[0] = cur_nums[0];
                    guess[1] = cur_nums[1];
                    guess[2] = cur_nums[2];
                    guess[3] = cur_nums[3];
                    return;
                }
                // 또는 모든 값이 다를 경우 ck2에 체크해준다.
                else if (res.strike == 0 && res.ball == 0)
                {
                    ck2[cur_nums[0]] = true;
                    ck2[cur_nums[1]] = true;
                    ck2[cur_nums[2]] = true;
                    ck2[cur_nums[3]] = true;
                }
                ck[i] = true;
                break;
            }
        }

        for (int i = 123; i <= 9876; i++)
        {
            if (ck[i])
                continue;

            // i에 대해서 int형 배열을 만든다.
            InttoArray(i, ans);

            // 만약 존재하지 않는 digit이 검출되었다면 pass한다.
            if (ck2[ans[0]] || ck2[ans[1]] || ck2[ans[2]] || ck2[ans[3]])
                continue;

            // 각 자리수중 겹치는 숫자가 존재하면 pass한다.
            if (diff(ans))
                continue;

            // query를 통해 얻은 결과와 비교하기 위해 현재 진행 중인 수와의 결과를 얻는다.
            Result cur = comp(cur_nums, ans);

            // 만약 strike 또는 ball의 수가 같지 않다면 다음 반복문에서 제외하기 위해 index를 이용하여 체크한다.
            if (res.strike != cur.strike || res.ball != cur.ball)
            {
                ck[i] = true;
            }
        }
        full_count++;
    }
}

static bool isValid(int guess[])
{
    int guess_c[10];

    for (int count = 0; count < 10; ++count)
        guess_c[count] = 0;
    for (int idx = 0; idx < N; ++idx)
    {
        if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0)
            return false;
        guess_c[guess[idx]]++;
    }
    return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[])
{
    Result result;

    if (querycount >= MAX_QUERYCOUNT)
    {
        result.strike = -1;
        result.ball = -1;
        return result;
    }

    querycount++;

    if (!isValid(guess))
    {
        result.strike = -1;
        result.ball = -1;
        return result;
    }

    result.strike = 0;
    result.ball = 0;

    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] == digits[idx])
            result.strike++;
        else if (digits_c[guess[idx]] > 0)
            result.ball++;

    return result;
}

static void initialize()
{
    for (int count = 0; count < 10; ++count)
        digits_c[count] = 0;
    for (int idx = 0; idx < N; ++idx)
    {
        char c;
        do
            scanf("%c", &c);
        while (c < '0' || c > '9');
        digits[idx] = c - '0';
        digits_c[digits[idx]]++;
    }

    querycount = 0;
}

static bool check(int guess[])
{
    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] != digits[idx])
            return false;
    return true;
}

int main()
{
    int total_score = 0;
    int total_querycount = 0;
    ;

    // freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        initialize();

        // int test_1[4] = {3, 1, 2, 0};
        // int test_2[4] = {3, 2, 1, 0};
        // printf("%d, %d\n", comp(test_1, test_2).strike, comp(test_1, test_2).ball);
        // return 0;
        int guess[N];
        doUserImplementation(guess);

        if (!check(guess))
            querycount = MAX_QUERYCOUNT;
        if (querycount <= limit_query)
            total_score++;
        printf("#%d %d\n", testcase, querycount);
        total_querycount += querycount;
    }
    if (total_querycount > MAX_QUERYCOUNT)
        total_querycount = MAX_QUERYCOUNT;
    printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
    return 0;
}