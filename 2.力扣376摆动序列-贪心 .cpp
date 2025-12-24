/*
本题题目为《摆动序列》力扣题号为376
题目链接：https://leetcode.cn/problems/wiggle-subsequence/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0],max_i = 0;
        //特殊处理
        if(size == 1)return nums[0];
        if(size == 0)return 0;
        
        //dp数组dp[i]代表第i下标结尾的最大值，初始化为原有值
        vector<int> dp(nums);
        //T数组T[i]代表第i下标结尾的子序列起始位置，默认全0
        vector<int> T(size,0);
        //从1开始
        for(int i = 1; i < size; i++){
            //当前大于之前的则忽略,并且最大起始设置为自己
            if(dp[i] >= dp[i] + dp[i-1]){
                T[i] = i;
            }
            else if(dp[i] < dp[i] + dp[i-1]){
                //当前小于则将之前的最大值和当前值相加，起始位置以前面元素的t数组为准
                T[i] = T[i-1];
                dp[i] = dp[i] + dp[i-1];
            }
        }
               
        for(int i = 0; i < size; i++){
            if(dp[i] >= max){
                max = dp[i];
                max_i = i;
            }
        }
        return max;
        
    }
};
