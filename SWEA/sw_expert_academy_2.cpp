#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_QUERYCOUNT 1000000
#define N 4

static int digits[N];
static int digits_c[10];

static int T;

//extern void doUserImplementation(int guess[]);

static int querycount;

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;

typedef struct
{
    int strike;
    int ball;
} Result;

// API

//extern Result query(int guess[]);

// {0, 1, 2, 3}을 시작으로 스트라이크, 볼 수가 같다. => 둘 다 0이다.. => 제외 => 이 숫자들은 아니기 때문에 같은 결과를 갖는 수들은 제외한다.
// => 뭔가 나왔다 => 스트라이크, 볼 수가 같은 수만 남긴다.. => 그럼 정답인 수와 같은 결과를 같는 수만 남는다.

Result comp(int ans[], int guess[])
{
    Result ret;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (ans[i] == guess[j])
                ret.ball++;
        }
        if (ans[i] == guess[i])
        {
            ret.ball--;
            ret.strike++;
        }
    }
}

void doUserImplementation(int guess[])
{
    // 완성된 4자리 숫자에 대한 체크
    bool ck[10000] = {
        0,
    };
    // 특정 1자리 숫자에 대한 체크 (계수)
    bool ck2[10] = {
        0,
    };
    while (true)
    {
        int ans[4];
        for (int i = 123; i <= 9876; i++)
        {
            if (i < 1000)
            {
                for (int j = 3; j > 0; j--)
                {
                    ans[j] = i % 10;
                    i /= 10;
                }
                ans[0] = 0;
            }
            else
            {
                for (int j = 3; j >= 0; j--)
                {
                    ans[j] = i % 10;
                    i /= 10;
                }
            }
            printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
        }
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
    {
        if (guess[idx] == digits[idx])
            result.strike++;
        else if (digits_c[guess[idx]] > 0)
            result.ball++;
    }

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
    //setbuf(stdout, NULL);

    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        initialize();

        int guess[N];
        doUserImplementation(guess);

        printf("%d\n", querycount);
        printf("guess : %d %d %d %d \n", guess[0], guess[1], guess[2], guess[3]);
        printf("digits : %d %d %d %d \n", digits[0], digits[1], digits[2], digits[3]);

        if (!check(guess))
        {
            querycount = MAX_QUERYCOUNT;
        }

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
