/*You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, 
such that the container contains the most water.
Return the maximum amount of water a container can store.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*Take two indexes let and right*/
    int left = 0;
    int right = height.size()-1;
    int currsum=0;
    int maxi = INT_MIN;
    while(left<right){
        currsum = min(height[left], height[right]) * (right-left);
        maxi = max(maxi,currsum);
        /* Move left forward if the height of left is less than the hright of right else decrement right*/
        if(height[left] < height[right]){left++;}
        else{
            right--;
        }
    }
    return maxi;
    }
};