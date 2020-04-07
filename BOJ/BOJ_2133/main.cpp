// https://www.acmicpc.net/problem/2133
// 타일 채우기

#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[31];

int solution(int width)
{
    if (width % 2 != 0)
        return 0;
    else if (width == 0)
        return 1;
    else if (width == 2)
        return 3;

    int &result = cache[width];
    if (result != -1)
        return result;

    result = 3 * solution(width - 2);
    for (int i = 0; i <= width - 4; i++)
    {
        result += 2 * solution(i);
    }
    return result;
}

int main()
{

    cin >> N;
    memset(cache, -1, sizeof(cache));

    cout << solution(N) << endl;

    return 0;
}