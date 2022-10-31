#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int range=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<range){
                count++;
                range=min(range,intervals[i][1]);
            }
            else{
                range=intervals[i][1];
            }
        }
        return count;
    }
};