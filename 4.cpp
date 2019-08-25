#include <vector>
#include <iostream>
using namespace std;

double kthsmallest(vector<int> &nums1, vector<int> &nums2, int k)
{
    // int m = nums1.size();
    // int n = nums2.size();
    //int k = (m + n + 1) / 2;                //寻找第k小的数
    //int label = ((m + n) % 2 == 0 ? 0 : 1); //标记总数的奇偶

    if (nums1.empty())
    {
        return nums2[k - 1];
    }
    if (nums2.empty())
    {
        return nums1[k - 1];
    }

    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();
    while (k > 1)
    {

        // if (*(it1 + k / 2 - 1) > *(it2 + k / 2 - 1))
        // {
        //     if(it2 + k / 2 <= nums2.end())
        //     {
        //         it2 += k / 2;
        //         k = k - k / 2;
        //     }
        //     else{
        //         k = k - (nums2.end() - it2);
        //         it2 = nums2.end();
        //     }
        // }
        // else if (*(it1 + k / 2 - 1) <= *(it2 + k / 2 - 1))
        // {
        //     if(it1 + k / 2 <= nums1.end())
        //     {
        //         it1 += k / 2;
        //         k = k - k / 2;
        //     }
        //     else{
        //         k = k - (nums1.end() - it1);
        //         it1 = nums1.end();
        //     }
        // }
        if (it1 + k / 2 <= nums1.end() && it2 + k / 2 <= nums2.end())
        {
            if (*(it1 + k / 2 - 1) > *(it2 + k / 2 - 1))
            {
                it2 += k / 2;
                k = k - k / 2;
            }
            else if (*(it1 + k / 2 - 1) <= *(it2 + k / 2 - 1))
            {
                it1 += k / 2;
                k = k - k / 2;
            }
        }
        else if (it1 + k / 2 <= nums1.end() && it2 + k / 2 > nums2.end())
        {
            if (*(it1 + k / 2 - 1) > *(nums2.end() - 1))
            {
                k = k - (nums2.end() - it2);
                it2 = nums2.end();
            }
            else if (*(it1 + k / 2 - 1) <= *(nums2.end() - 1))
            {
                it1 += k / 2;
                k = k - k / 2;
            }
        }
        else if (it1 + k / 2 > nums1.end() && it2 + k / 2 <= nums2.end())
        {
            if (*(nums1.end() - 1) > *(it2 + k / 2 - 1))
            {
                it2 += k / 2;
                k = k - k / 2;
            }
            else if (*(nums1.end() - 1) <= *(it2 + k / 2 - 1))
            {
                k = k - (nums1.end() - it1);
                it1 = nums1.end();
            }
        }

        if (it1 == nums1.end())
        {
            return *(it2 + k - 1);
        }
        if (it2 == nums2.end())
        {
            return *(it1 + k - 1);
        }
    }
    // if (label == 0)
    // {
    //     return (double)(*it1 + *it2) / 2;
    // }
    // else
    // {
    //     return *it1 > *it2 ? *it2 : *it1;
    // }
    return (double)min(*it1, *it2);
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int label = ((m + n) % 2 == 0 ? 0 : 1); //标记总数的奇偶
    int k = (m + n + 1) / 2;                //寻找第k小的数
    if (label == 0)
    {
        return (kthsmallest(nums1, nums2, k) + kthsmallest(nums1, nums2, k + 1)) / 2;
    }
    else
    {
        return kthsmallest(nums1, nums2, k);
    }
}

int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {0, 3};
    cout << "------" << endl;
    cout << findMedianSortedArrays(a, b) << endl;
    cout << "------" << endl;
    return 0;
}