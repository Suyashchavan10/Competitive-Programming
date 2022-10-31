#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)
	    {
		    return;
	    }
	    int n = nums.size()-1;
	    int index1 = 0,index2=0;
	    for(index1=n-1;index1>=0;index1--)
	    {
		    if(nums[index1]<nums[index1+1])
		    {
			    break;
		    }
	    }
	    if(index1<0)
	    {
		    reverse(nums.begin(),nums.end());
	    }
	    else
	    {
		    for(index2=n;index2>index1;index2--)
		    {   
			    if(nums[index2]>nums[index1])
			    {
				    break;
			    }
		    }
            swap(nums[index1],nums[index2]);
	        reverse(nums.begin()+index1+1,nums.end()); 
	    }
    }
};
int main()
{
    int n;
    vector<int> nums(n);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    Solution obj;
    obj.nextPermutation(nums);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    return 0;
}