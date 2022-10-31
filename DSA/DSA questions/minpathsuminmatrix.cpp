/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
 which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 9999999));
        
        // Make way for entry in loop
        dp[0][1] = 0;
        
        for(int i = 1; i <= grid.size(); i++)
            for(int j = 1; j <= grid[0].size(); j++)
                dp[i][j] = grid[i - 1][j-1] + min(dp[i][j-1], dp[i-1][j]);
                
        return dp[grid.size()][grid[0].size()];
    }
};