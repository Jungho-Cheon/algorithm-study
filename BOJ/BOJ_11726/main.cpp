// https://www.acmicpc.net/problem/11726
// 2xn 타일링

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int DP[3] = {0, 1, 2};

    if (N < 3){
        cout << DP[N] << endl;
        return 0;
    }

    for(int i = 2; i < N; i++){
        int tmp = DP[2];
        DP[2] = (DP[2] + DP[1]) % 10007;
        DP[1] = tmp;
    }

    cout << DP[2] % 10007 << endl;

    return 0;
}


