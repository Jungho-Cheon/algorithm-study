#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 30000
#define a 17
#define b 7
#define HASHSIZE 100019

#define one 1111111111111111

// 1. 16자리 숫
typedef long long ll;
ll hash_table[HASHSIZE], cur[4];
int turn[2][16];
int sum;

struct block
{
    int maxH;
    int minH;
    ll state;
};
block bl[MAX + 1];

void init()
{
    for (int i = 0; i < HASHSIZE; i++)
    {
        hash_table[i] = -1;
    }
    sum = 0;
}

void insert(ll key)
{
    int p = (key) % HASHSIZE;

    while (hash_table[p] != -1)
    {
        p = (p + 1) % HASHSIZE;
    }
    hash_table[p] = key;
}

int find(ll key)
{
    int p = (key) % HASHSIZE;

    while (hash_table[p] != key)
    {
        if (hash_table[p] == -1)
            return -1;
        p = (p + 1) % HASHSIZE;
    }
    return p;
}

ll returnstate(int p)
{
    ll tmp = 0;
    for (int i = 0; i < 16; i++)
    {
        tmp = tmp * 10 + turn[p][i];
    }
    return tmp;
}

void findpair(ll state, int maxH)
{
    int tmp[16]; // state가 합쳐질 수 있는 가장 높은 블럭 (이상)
    for (int i = 0; i < 16; i++)
    {
        tmp[15 - i] = maxH - (state % 10);
        state /= 10;
    }

    int t = 12;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            turn[0][t + j] = tmp[i * 4 + j];
        }
        t -= 4;
    }
    cur[0] = returnstate(0);

    for (int c = 1; c < 4; c++)
    {
        int p = 0;
        for (int i = 12; i <= 15; i++)
        {
            int tt = i;
            while (tt >= 0)
            {
                turn[c % 2][p] = turn[(c + 1) % 2][tt];
                tt -= 4;
                p++;
            }
        }
        cur[c] = returnstate(c % 2);
    }
}

int makeBlock(int module[][4][4])
{
    init();
    // 블록은 1자로 쭉늘려 hash_table에 넣는다.
    for (int i = 0; i < MAX; i++)
    {
        ll t = 0;
        int maxH = 0;
        int minH = 10;
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int m = module[i][j][k];
                t = t * 10 + m;
                maxH = maxH < m ? m : maxH;
                minH = minH > m ? m : minH;
            }
        }
        insert(t);
        bl[i].maxH = maxH;
        bl[i].minH = minH;
        bl[i].state = t;
    }

    for (int i = 0; i < MAX; i++)
    {
        int v = find(bl[i].state);
        if (v == -1)
            continue;

        findpair(bl[i].state, bl[i].minH + 8);

        for (int j = bl[i].minH + 8; j >= bl[i].maxH + 1; j--)
        {
            bool f = false;
            for (int k = 0; k < 4; k++)
            {
                int p = find(cur[k]);
                if (p != -1 && cur[k] != bl[i].state)
                {
                    hash_table[p] = -1;
                    p = find(bl[i].state);
                    hash_table[p] = -1;

                    sum += j;
                    f = true;
                    break;
                }
                cur[k] -= one;
            }
            if (f)
                break;
        }
    }
    return sum;
}

///////////

int main(void)
{
    static int module[MAX][4][4];

    srand(3); // 3 will be changed

    for (int tc = 1; tc <= 10; tc++)
    {
        for (int c = 0; c < MAX; c++)
        {
            int base = 1 + (rand() % 6);
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    module[c][y][x] = base + (rand() % 3);
                }
            }
        }
        cout << "#" << tc << " " << makeBlock(module) << endl;
    }

    return 0;
}