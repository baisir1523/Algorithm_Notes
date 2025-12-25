/*
本题题目为《反转字符串》力扣题号为344
题目链接：https://leetcode.cn/problems/reverse-string/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0,right = s.size()-1;

        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
