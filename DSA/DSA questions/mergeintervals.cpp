/*Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the non-overlapping 
intervals that cover all the intervals in the input.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto it: intervals){
            if(ans.back()[1] >= it[0]) ans.back()[1] = max(ans.back()[1], it[1]);
            else ans.push_back(it);
        }
        return ans;
    }
};