#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//位运算
int hammingDistance(int x, int y)
{
    x = x ^ y;
    y = 0;
    while (x != 0)
    {
        if (x & 1 == 1)
        {
            y++;
        }
        x = x >> 1;
    }
    return y;
}

void test()
{
}

int main()
{
    test();
    return 0;
}