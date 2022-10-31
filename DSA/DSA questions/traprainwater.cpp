/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it can trap after raining. */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){ return 0;}
        int ans=0;
        int n=height.size();
        vector<int>l1(n,0),r1(n,0);
        l1[0]=height[0];
        r1[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            l1[i]=max(height[i],l1[i-1]);
        }
        for(int i=n-2;i>=0;i--){

            r1[i]=max(height[i],r1[i+1]);
        }
        for(int i=0;i<n;i++){
            ans+=(min(l1[i],r1[i])-height[i]);
            
        }
        return ans;
    }
};