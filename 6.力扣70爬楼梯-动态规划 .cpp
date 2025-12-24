/*
本题题目为《爬楼梯》力扣题号为70
题目链接：https://leetcode.cn/problems/climbing-stairs/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
    	//特殊情况的处理（题目已经给出特殊情况的值）
        if(n == 1)return 1;
        if(n == 2)return 2;
        //为了方便理解，我们从数组下标1开始，则dp数组长度要加1
        //dp[i]代表到达第i个台阶有dp[i]种不同的方法
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
		//这一步类似于斐波那契，将前面的累加起来
		//因为前面的两个台阶已经是局部最优解了，因此加上他们再一次构成局部最优解
        for(int i = 3; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
