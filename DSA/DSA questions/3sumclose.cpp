/*Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int closest=INT_MAX;
        int prev_diff=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(prev_diff>abs(nums[i]+nums[j]+nums[k]-target)){
                    closest=(nums[i]+nums[j]+nums[k]);
                    prev_diff=abs(nums[i]+nums[j]+nums[k]-target);
                }
                if(nums[i]+nums[j]+nums[k]==target){
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1])
                    j++;
                    while(j<k&&nums[k]==nums[k+1])
                    k++;
                }
                else if(nums[i]+nums[j]+nums[k]>target)    
                    k--;
                else
                    j++;
                
            }
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
        }
        
        return closest; 
    }
};