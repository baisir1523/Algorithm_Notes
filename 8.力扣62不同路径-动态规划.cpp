/*
本题题目为《不同路径》力扣题号为62
题目链接：https://leetcode.cn/problems/unique-paths/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {

        //到座标为（m，n）的位置共有dp[m][n]条路径,dp初始化为全1
        vector<vector<int>> dp(m+1, vector<int>(n+1, 1));

        for(int i = 2; i <= m; i++){
            for(int j = 2; j <= n; j++){
            	//到达(i,j)坐标的路径由前面的(i-1,j)和(i,j-1)的路径数量相加得到
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m][n];
    }
};
