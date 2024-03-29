# leetcode

## 介绍
leetcode刷题记录(https://leetcode-cn.com)

## 1. 题目汇总
3.无重复字符的最长子串----滑动窗口  
4.（hard）寻找两个有序数组的中位数----分治  
5.最长回文子串----Manacher(马拉车)算法  
10.（hard）正则表达式匹配----动态规划  
11.盛最多水的容器----双指针  
15.三数之和----双指针（三指针）  
17.电话号码的字母组合----回溯  
19.删除链表的倒数第N个节点----双指针  
20.有效的括号----栈  
21.合并两个有序链表----递归  
22.括号生成----回溯  
23.（hard）合并K个排序链表----优先队列（小根堆）  
28.字符串的模式匹配----KMP算法 和 BM(Boyer-Moore)算法  
31.下一个排列----巧计  
32.（hard）最长有效括号----栈  
33.搜索旋转排序数组----二分查找  
34.在排序数组中查找元素的第一个和最后一个位置----二分查找  
39.组合总和----回溯  
42.（hard）接雨水----双指针或栈  
46.全排列----回溯  
48.旋转图像----数组变换  
49.字母异位词分组----哈希表  
53.最大子序和----动态规划  
55.跳跃游戏----贪心  
56.合并区间----贪心  
62.不同路径----动态规划  
64.最小路径和----动态规划  
70.爬楼梯----动态规划  
72.（hard）编辑距离----动态规划  
75.颜色分类----双指针  
76.（hard）最小覆盖子串----滑动窗口  
78.子集----动态规划  
79.单词搜索----回溯  
84.（hard）柱状图中最大的矩形----栈（单调栈）  
85.（hard）最大矩形----栈（单调栈）  
94.二叉树的中序遍历----递归或迭代（栈）  
96.不同的二叉搜索树----动态规划  
98.验证二叉搜索树----递归或迭代（栈）  
101.对称二叉树----递归或迭代（队列）  
102.二叉树的层次遍历----递归或迭代（队列）  
104.二叉树的最大深度----递归或迭代（队列）  
105.从前序与中序遍历序列构造二叉树----递归或迭代（栈）  
106.从中序与后序遍历序列构造二叉树----递归或迭代（栈）  
114.二叉树展开为链表----巧计  
121.买卖股票的最佳时机----动态规划  
122.买卖股票的最佳时机II----贪心  
123.（hard）买卖股票的最佳时机III----动态规划  
188.（hard）买卖股票的最佳时机IV----动态规划  
124.（hard）二叉树中的最大路径和----递归  
128.（hard）最长连续序列----哈希表  
136.只出现一次的数字----位运算  
139.单词拆分----动态规划  
141.环形链表----双指针  
142.环形链表II----双指针  
146.LRU缓存机制----哈希表和双向链表  
148.排序链表----分治（归并）  
152.乘积最大子序列----动态规划  
155.最小栈----栈  
160.相交链表----双指针  
169.求众数----Boyer-Moore(摩尔)投票算法  
198.打家劫舍----动态规划  
200.岛屿数量----广度优先搜索（队列）  
206.反转链表----双指针（三指针）  
207.课程表----广度优先搜索（队列）  
215.数组中的第K个最大元素----分治（快排）  
221.最大正方形----动态规划  
226.翻转二叉树----递归或迭代（队列）  
234.回文链表----双指针（三指针）  
236.二叉树的最近公共祖先----递归  
238.除自身以外数组的乘积----动态规划  
239.（hard）滑动窗口最大值----动态规划或队列（双向队列）  
240.搜索二维矩阵II----贪心  
279.完全平方数----动态规划或回溯  
283.移动零----双指针  
287.寻找重复数----二分查找  
297.（hard）二叉树的序列化与反序列化----递归  
300.最长上升子序列----动态规划  
309.最佳买卖股票时机含冷冻期----动态规划  
312.戳气球----动态规划  
322.零钱兑换----动态规划或回溯  
337.打家劫舍III----动态规划  
338.比特位计数----位运算和动态规划  
347.前K个高频元素----哈希表  
394.字符串解码----栈或回溯  
406.根据身高重建队列----贪心  
416.分割等和子集----动态规划或回溯  
437.路径总和III----递归  
438.找到字符串中所有字母异位词----滑动窗口  
448.找到所有数组中消失的数字----巧记  
461.汉明距离----位运算  
494.目标和----动态规划  
538.把二叉搜索树转换为累加树----递归  
543.二叉树的直径----递归  
560.和为K的子数组----哈希表  
581.最短无序连续子数组----巧记  
617.合并二叉树----递归  
621.任务调度器----贪心  
647.回文子串----中心扩展法  
739.每日温度----栈  

## 2. 方法汇总

### 广度优先搜索 回溯（深度优先搜索）
17.电话号码的字母组合----回溯  
22.括号生成----回溯  
39.组合总和----回溯  
46.全排列----回溯  
79.单词搜索----回溯  
200.岛屿数量----广度优先搜索（队列）  
207.课程表----广度优先搜索（队列）  
322.零钱兑换----动态规划或回溯  
394.字符串解码----栈或回溯  
416.分割等和子集----动态规划或回溯  

### 分治 二分查找
4.（hard）寻找两个有序数组的中位数----分治  
33.搜索旋转排序数组----二分查找  
34.在排序数组中查找元素的第一个和最后一个位置----二分查找  
148.排序链表----分治（归并）  
215.数组中的第K个最大元素----分治（快排）  
287.寻找重复数----二分查找  

### 动态规划
10.（hard）正则表达式匹配----动态规划  
53.最大子序和----动态规划  
62.不同路径----动态规划  
64.最小路径和----动态规划  
70.爬楼梯----动态规划  
72.（hard）编辑距离----动态规划  
78.子集----动态规划  
96.不同的二叉搜索树----动态规划  
121.买卖股票的最佳时机----动态规划  
123.（hard）买卖股票的最佳时机III----动态规划  
188.（hard）买卖股票的最佳时机IV----动态规划  
309.最佳买卖股票时机含冷冻期----动态规划  
139.单词拆分----动态规划  
152.乘积最大子序列----动态规划  
198.打家劫舍----动态规划  
221.最大正方形----动态规划  
238.除自身以外数组的乘积----动态规划  
239.（hard）滑动窗口最大值----动态规划或队列（双向队列）  
279.完全平方数----动态规划或回溯  
300.最长上升子序列----动态规划  
312.戳气球----动态规划  
322.零钱兑换----动态规划或回溯  
337.打家劫舍III----动态规划或递归  
338.比特位计数----位运算和动态规划  
416.分割等和子集----动态规划或回溯  
494.目标和----动态规划  

### 双指针
11.盛最多水的容器----双指针  
15.三数之和----双指针（三指针）  
19.删除链表的倒数第N个节点----双指针  
42.（hard）接雨水----双指针或栈  
75.颜色分类----双指针  
141.环形链表----双指针  
142.环形链表II----双指针  
160.相交链表----双指针  
206.反转链表----双指针（三指针）  
234.回文链表----双指针（三指针）  
283.移动零----双指针  

### 滑动窗口
3.无重复字符的最长子串----滑动窗口  
76.（hard）最小覆盖子串----滑动窗口  
438.找到字符串中所有字母异位词----滑动窗口  

### 栈
20.有效的括号----栈  
32.（hard）最长有效括号----栈  
42.（hard）接雨水----双指针或栈  
84.（hard）柱状图中最大的矩形----栈（单调栈）  
85.（hard）最大矩形----栈（单调栈）  
94.二叉树的中序遍历----递归或迭代（栈）  
98.验证二叉搜索树----递归或迭代（栈）  
105.从前序与中序遍历序列构造二叉树----递归或迭代（栈）  
106.从中序与后序遍历序列构造二叉树----递归或迭代（栈）  
155.最小栈----栈  
394.字符串解码----栈或回溯  
739.每日温度----栈  

### 队列
23.（hard）合并K个排序链表----优先队列（小根堆）  
101.对称二叉树----递归或迭代（队列）  
102.二叉树的层次遍历----递归或迭代（队列）  
104.二叉树的最大深度----递归或迭代（队列）  
200.岛屿数量----广度优先遍历（队列）  
207.课程表----广度优先遍历（队列）  
226.翻转二叉树----递归或迭代（队列）  
239.（hard）滑动窗口最大值----动态规划或队列（双向队列）  

### 树递归（回溯）
21.合并两个有序链表----递归  
94.二叉树的中序遍历----递归或迭代（栈）  
98.验证二叉搜索树----递归或迭代（栈）  
101.对称二叉树----递归或迭代（队列）  
102.二叉树的层次遍历----递归或迭代（队列）  
104.二叉树的最大深度----递归或迭代（队列）  
105.从前序与中序遍历序列构造二叉树----递归或迭代（栈）  
106.从中序与后序遍历序列构造二叉树----递归或迭代（栈）  
124.（hard）二叉树中的最大路径和----递归  
226.翻转二叉树----递归或迭代（队列）  
236.二叉树的最近公共祖先----递归  
297.（hard）二叉树的序列化与反序列化----递归  
337.打家劫舍III----动态规划或递归  
437.路径总和III----递归  
538.把二叉搜索树转换为累加树----递归  
543.二叉树的直径----递归  
617.合并二叉树----递归  

### 贪心 巧计 特殊算法
5.最长回文子串----Manacher(马拉车)算法  
28.字符串的模式匹配----KMP算法 和 BM(Boyer-Moore)算法  
31.下一个排列----巧计  
55.跳跃游戏----贪心  
56.合并区间----贪心  
114.二叉树展开为链表----巧计  
122.买卖股票的最佳时机II----贪心  
169.求众数----Boyer-Moore(摩尔)投票算法  
240.搜索二维矩阵II----贪心  
406.根据身高重建队列----贪心  
448.找到所有数组中消失的数字----巧记  
581.最短无序连续子数组----巧记  
621.任务调度器----贪心  
647.回文子串----中心扩展法  

### 哈希表
49.字母异位词分组----哈希表  
128.（hard）最长连续序列----哈希表  
146.LRU缓存机制----哈希表和双向链表  
347.前K个高频元素----哈希表  
560.和为K的子数组----哈希表  

### 位运算
136.只出现一次的数字----位运算  
338.比特位计数----位运算和动态规划  
461.汉明距离----位运算  

## 3. 数据结构

### 链表
19.删除链表的倒数第N个节点----双指针  
21.合并两个有序链表----递归  
23.（hard）合并K个排序链表----优先队列（小根堆）  
141.环形链表----双指针  
142.环形链表II----双指针  
146.LRU缓存机制----哈希表和双向链表  
148.排序链表----分治（归并）  
160.相交链表----双指针  
206.反转链表----双指针（三指针）  
234.回文链表----双指针（三指针）  

### 树
94.二叉树的中序遍历----递归或迭代（栈）  
98.验证二叉搜索树----递归或迭代（栈）  
101.对称二叉树----递归或迭代（队列）  
102.二叉树的层次遍历----递归或迭代（队列）  
104.二叉树的最大深度----递归或迭代（队列）  
105.从前序与中序遍历序列构造二叉树----递归或迭代（栈）  
106.从中序与后序遍历序列构造二叉树----递归或迭代（栈）  
114.二叉树展开为链表----巧计  
124.（hard）二叉树中的最大路径和----递归  
226.翻转二叉树----递归或迭代（队列）  
236.二叉树的最近公共祖先----递归  
297.（hard）二叉树的序列化与反序列化----递归  
337.打家劫舍III----动态规划或递归  
437.路径总和III----递归  
538.把二叉搜索树转换为累加树----递归  
543.二叉树的直径----递归  
617.合并二叉树----递归  

### 网格（二维数组）
48.旋转图像----数组变换  
79.单词搜索----回溯  
62.不同路径----动态规划  
64.最小路径和----动态规划  
85.（hard）最大矩形----栈（单调栈）  
200.岛屿数量----广度优先遍历  
221.最大正方形----动态规划  
240.搜索二维矩阵II----贪心  

### 设计
146.LRU缓存机制----哈希表和双向链表  
155.最小栈----栈  
297.（hard）二叉树的序列化与反序列化----递归  