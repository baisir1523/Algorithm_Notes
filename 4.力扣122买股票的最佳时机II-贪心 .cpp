/*
本题题目为《买股票的最佳时机II》力扣题号为122
题目链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // 累加所有正的价格差
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};
