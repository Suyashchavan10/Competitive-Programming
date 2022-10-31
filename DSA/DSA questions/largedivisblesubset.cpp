#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
         int ans = 1, n = size(nums);
         vector<int> dp(n, 1);
         vector<int> INDEX(n);
         int tbi = -1;
         for(int i = 0; i < n; i++) {
             INDEX[i] = i;
               for(int j = 0; j < i; j++) {
                 if(nums[i]%nums[j]==0) {
                    if(dp[j]+1>dp[i]){
                        INDEX[i] = j;
                        
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                }
               }
             
         }
         tbi = max_element(dp.begin(),dp.end())-dp.begin();
         vector<int> result;
         while(INDEX[tbi]!=tbi){
             result.push_back(nums[tbi]);
             tbi = INDEX[tbi];
         }
	      result.push_back(nums[tbi]);	    
        //  cout<< ans;
        return result; 
    }
};