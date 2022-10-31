/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> v;
        for(int i=0;i<n-2;i++)
        {
            int j=i+1;
            int k=n-1;
            int target= -nums[i];
            while(j<k)
            {
                if(nums[j]+nums[k]==target)
                {
                    v.insert({nums[i], nums[j] , nums[k]});
                    j++;k--;
                }
                else if(nums[j]+nums[k]<target)
                {
                    j++;
                }
                else
                    k--;
            }
        }
        vector<vector<int>> myvec;
        for(auto i:v)
        {
            myvec.push_back(i);
        }
        return myvec;
    }
};