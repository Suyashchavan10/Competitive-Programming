/*Given an integer array nums, return the maximum difference between two successive elements 
in its sorted form. If the array contains less than two elements, return 0.
You must write an algorithm that runs in linear time and uses linear extra space.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(n==2){
            return abs(nums[0]-nums[1]);
        }
        int power=1;
        int maxDigits=log10(*max_element(nums.begin(),nums.end()))+1;
        bool check=true;
        while(maxDigits--){
            vector<int> temp(n);
            vector<int>count(10,0);
            for(int i=0;i<n;i++){
                int digit=(int)(nums[i]/power)%10;
                count[digit]++;
            }
            for(int i=1;i<10;i++)
                count[i]+=count[i-1];
            for(int i=n-1;i>=0;i--){
                int digit=(int)(nums[i]/power)%10;
                temp[--count[digit]]=nums[i];
            }
            nums=temp;
            power*=10;
            
        }
        int ans=abs(nums[0]-nums[1]);
        for(int i:nums){
            cout<<i<<" ";
        }
        for(int i=1;i<n;i++){
            ans=max(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;
    }
};