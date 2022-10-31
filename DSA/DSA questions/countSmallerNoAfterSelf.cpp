#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void update(vector<long long int> &bit, int i, int x, int n)
    {
        while(i <= n)
        {
            bit[i] += x;
            i += i&(-i);
        }
    }
    int ps(vector<long long int> &bit, int i)
    {
        int sum = 0;
        while(i > 0)
        {
            sum += bit[i];
            i -= i&(-i);
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        int N = 2e5+2;
        vector<int> counts(n);
        vector<long long int> bit(N, 0);
        for(int i=0;i<n;i++)
            nums[i] += 1e4+1;
        for(int i=n-1;i>=0;i--)
        {
            update(bit, nums[i], 1, N);
            counts[i] = ps(bit, nums[i]-1);
        }
        return counts;
    }
};