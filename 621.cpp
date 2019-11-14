#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//贪心，将个数最多的任务划分开，间隔n，addNum表示待命的数目，如果addNum小于0，说明不需要待命的位置
int leastInterval(vector<char> &tasks, int n)
{
    int map[26]{0};
    for (char &c : tasks)
    {
        map[c - 'A']++;
    }
    sort(map, map + 26);
    int insertPos = map[25] - 1, addNum = insertPos * n;
    for (int i = 24; i >= 0 && map[i] > 0; --i)
    {
        addNum -= min(insertPos, map[i]);
    }
    addNum = max(0, addNum);
    return addNum + tasks.size();
}

void test()
{
}

int main()
{
    test();
    return 0;
}
