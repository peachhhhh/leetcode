#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//基于队列的广度优先搜索，将入度为0的节点入队，每出队一个点，计一次数，最后和总节点数比较，判断是否有环路
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> points(numCourses);
    vector<int> indegrees(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        points[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegrees[prerequisites[i][0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        count++;
        for (int i = 0; i < points[tmp].size(); i++)
        {
            indegrees[points[tmp][i]]--;
            if (indegrees[points[tmp][i]] == 0)
            {
                q.push(points[tmp][i]);
            }
        }
    }
    return numCourses == count;
}

void test()
{
}

int main()
{
    test();
    return 0;
}