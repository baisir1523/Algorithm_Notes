/*
本题题目为《二分查找》力扣题号为704
题目链接：https://leetcode.cn/problems/binary-search/description/
*/
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + ((right - left)/2);
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(target < nums[mid]){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
