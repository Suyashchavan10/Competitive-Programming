#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[102][102];
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k){
        
        if(k >= s3.size()) 
            return true;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool flag1 = false, flag2 = false;
        if(s1[i] == s3[k]){
            flag1 =  solve(s1, s2, s3, i + 1, j, k + 1);
        }
        
        if(s2[j] == s3[k]){
            flag2 =  solve(s1, s2, s3, i, j + 1, k + 1);
        }
    
        return dp[i][j] = (flag1 || flag2);
        
    }
    bool isInterleave(string s1, string s2, string s3) {
         if((s1.size() + s2.size()) != s3.size()) return false;
         memset(dp, -1,sizeof(dp));         
         return solve(s1, s2, s3, 0 , 0 , 0);
    }
};