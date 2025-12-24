/*
本题题目为《分发饼干》力扣题号为455
题目链接：leetcode.cn/problems/assign-cookies/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int count=0;
        //保证数组有序
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //一旦某个数组走到头则终止循环
        while(i<g.size()&j<s.size()){
            if(g[i]<=s[j]){
                //开始满足，如果饼干可以满足当前孩子则都向后移动并且总数加一
                count++;
                i++;j++;
            }
            else{
                //没有满足则代表胃口太大，向后移动s数组用更大的饼干满足
                j++;
            }
            
        }
        //输出结果
        return count;
    }
};
