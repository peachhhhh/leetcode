#include <iostream>
#include <vector>
using namespace std;

//分治，二分查找（有待改进缩短）
int search(vector<int> &v, int num)
{
    if (v.empty())
    {
        return -1;
    }
    int left = 0, right = v.size() - 1;
    if (num < v[left] && num > v[right])
    {
        return -1;
    }
    int mid = (left + right) / 2;
    do
    {
        if (v[mid] < v[right])
        {
            if (num >= v[mid] && num <= v[right])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        else
        {
            if (num > v[mid] || num < v[left])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        mid = (left + right) / 2;
    } while (left < right - 1);

    if (num == v[left])
    {
        return left;
    }
    else if (num == v[right])
    {
        return right;
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> v{1, 3};
    cout << search(v, 3) << endl;
    return 0;
}