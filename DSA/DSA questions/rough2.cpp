#include<bits/stdc++.h>
using namespace std;
int arr[100000000];
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
int countHousePlacements(int n) {
        int MOD = 1e9+7;
        if(n == 1)
            return 4;
        int x, y;
        if(n%2 == 0)
        {
            x = n/2;
            y = n/2;
        }
        else
        {
            x = n/2;
            y = y/2 +1;
        }
        int ans;
        ans = (int)(pow(2, x)+0.5) + (int)(pow(2, y)+0.5) - 1;
        ans = (int)(pow(ans, 2)+0.5);
        return ans;
    }

void update1(vector<int> &bit, int i, int n)
    {
        while(i <= n)
        {
            bit[i] += 1;
            i += i&(-i);
        }
    }
    void update2(vector<int> &bit, int i)
    {
        while(i > 0)
        {
            bit[i] += 1;
            i -= i&(-i);
        }
    }
    int ps1(vector<int> &bit, int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += bit[i];
            i -= i&(-i);
        }
        return sum;
    }
    int ps2(vector<int> &bit, int i, int n)
    {
        int sum = 0;
        while(i <= n)
        {
            sum += bit[i];
            i += i&(-i);
        }
        return sum;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int maxm = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxm = max(maxm, rating[i]);
        }
        int m = maxm;
        vector<int> BITLS(m, 0);
        vector<int> BITRS(m, 0);
        vector<int> BITLB(m, 0);
        vector<int> BITRB(m, 0);
        vector<int> LS(n, 0);
        vector<int> RS(n, 0);
        vector<int> LB(n, 0);
        vector<int> RB(n, 0);
        for(int i=n-1;i>=0;i--)
        {
            update1(BITRS, rating[i], m);
            RS[i] = ps1(BITRS, rating[i]-1);
            update2(BITRB, rating[i]);
            RB[i] = ps2(BITRB, rating[i]-1, m);
        }
        for(int i=0;i<n;i++)
        {
            update1(BITLS, rating[i], m);
            LS[i] = ps1(BITLS, rating[i]-1);
            update2(BITLB, rating[i]);
            LB[i] = ps2(BITLB, rating[i]-1, m);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += LS[i]*RB[i];
            ans += LB[i]*RS[i];
        }
        return ans;
    }

int main()
{
    /*int n;
    cin>>n;
    vector<int> nums(n);
    
    for(int i=0;i<n;i++)
        cin>>nums[i];
    nextPermutation(nums);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
    return 0;*/
    vector<int> rating = {2, 5, 3, 4, 1};
	cout<<numTeams(rating);
}