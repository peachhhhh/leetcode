#include <iostream>
#include <vector>
using namespace std;

//双指针一头一尾，每次对应值小的一侧指针移动，并更新左右最高点和雨水值。
int trap(vector<int> &height)
{
    if (height.empty())
    {
        return 0;
    }
    vector<int>::iterator it1 = height.begin(), it2 = height.end() - 1;
    int sum = 0;
    int leftmax = 0, rightmax = 0;
    while (it1 < it2)
    {
        if (*it1 < *it2)
        {
            if (*it1 < leftmax)
            {
                sum = sum + leftmax - *it1;
            }
            else
            {
                leftmax = *it1;
            }
            it1++;
        }
        else
        {
            if (*it2 < rightmax)
            {
                sum = sum + rightmax - *it2;
            }
            else
            {
                rightmax = *it2;
            }
            it2--;
        }
    }
    return sum;
}

int main()
{
    vector<int> v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(v) << endl;
    return 0;
}