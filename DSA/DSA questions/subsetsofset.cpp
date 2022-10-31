/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > subset;
        for(int i=0;i<(1<<n);i++)
        {
            vector<int> subseti;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                    subseti.push_back(nums[j]);
            }
            subset.push_back(subseti);
        }
        return subset;
    }
};