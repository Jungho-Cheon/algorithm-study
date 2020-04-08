#include <iostream>
#include <algorithm>

using namespace std;

int max_length(string t)
{
    int count = t[0] - '0';
    int ret = 0;

    for (int i = 1; i < t.length(); i++)
    {
        if (t[i] == '1')
        {
            if (t[i - 1] == '1')
                count++;
            else
                count = 1;
        }
        else
        {
            ret = max(ret, count);
            count = 0;
        }
    }
    return ret;
}

int main()
{
    string tmp = "11111100111011111";

    cout << max_length(tmp + "0") << endl;

    return 0;
}