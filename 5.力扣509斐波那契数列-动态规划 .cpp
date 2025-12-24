/*
本题题目为《斐波那契数列》力扣题号为509
题目链接：https://leetcode.cn/problems/fibonacci-number/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if(n == 0)return 0;
        if(n == 1)return 1;

        vector<int> arr(n+1,0);
        arr[0] = 0;
        arr[1] = 1;

        for(int i = 2; i < n+1; i++){
            arr[i] = arr[i-1] + arr[i - 2];
        }

        return arr[n];

    }
};
