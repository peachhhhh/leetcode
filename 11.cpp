#include <vector>
#include <iostream>
using namespace std;

//双指针，只允许较矮一侧的指针进行移动，一旦变高或超过较高一侧，则计算面积。
int maxArea(vector<int> &height)
{
    vector<int>::iterator it1, it2;
    it1 = height.begin();
    it2 = height.end() - 1;
    int area = min(*it1, *it2) * (it2 - it1);
    int maxarea = area;
    while (it1 < it2)
    {
        if (*it1 < *it2)
        {
            while (it1 < it2 && *it1 < *it2)
            {
                it1++;
                if(*it1 > *(it1 - 1)){
                    break;
                }
            }
        }
        else if (*it1 >= *it2)
        {
            while (it1 < it2 && *it1 >= *it2)
            {
                it2--;
                if(*it2 > *(it2 - 1)){
                    break;
                }
            }
        }
        area = min(*it1, *it2) * (it2 - it1);
        maxarea = max(maxarea, area);
    }
    return maxarea;
}

int main()
{
    vector<int> a = {1,1};
    cout << maxArea(a) << endl;
    return 0;
}