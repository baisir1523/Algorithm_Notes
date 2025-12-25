/*
本题题目为《不同路径II》力扣题号为63
题目链接：https://leetcode.cn/problems/unique-paths-ii/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //如果一开始就有石头则都不可达
        if(obstacleGrid[0][0] == 1)return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //dp[m][n]代表到达坐标点(m,n)共有多少条路径
        //dp数组目前初始化全为1
        vector<vector<int>> dp(m, vector<int>(n, 1));
        //初始化dp数组最上面的边，一旦某一点为0则之后的全部不可达
        int temp = 1;
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] != 0 || temp == 0){
                temp = 0;
                dp[0][i] = temp;
            }else{
                dp[0][i] = 1;
            }
        }
        //初始化dp数组最左面的边，一旦某一点为0则之后的全部不可达
        temp = 1;
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] != 0 || temp == 0){
                temp = 0;
                dp[i][0] = temp;
            }else{
                dp[i][0] = 1;
            }
        }
		
		
        for(int i = 1;i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i][j - 1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m -1][n - 1];
    }
};
