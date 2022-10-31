#include<bits/stdc++.h>
using namespace std;

struct stNode
{
    int sum;
    int maxm;
};

void buildST(vector<struct stNode> &ST, vector<int> &vect, int size)
{
    int N = ST.size(), n = vect.size();
    for(int i=0; i<n; i++)
    {
        ST[i+ size-1].sum = vect[i];
        ST[i+ size-1].maxm = vect[i];
    }
    int ind = size - 2;
    while(ind >= 0)
    {
        ST[ind].sum = ST[2*ind+1].sum + ST[2*ind+2].sum;
        ST[ind].maxm = max(ST[2*ind+1].maxm, ST[2*ind+2].maxm);
        ind--;
    }
    return ;
}

void update(vector<struct stNode> &ST, int ind, int val, int size)
{
    int pt = ind + size -1;
    ST[pt].sum = val;
    ST[pt].maxm = val;
    pt = (pt-1)/2;

    while(pt >= 0)
    {
        ST[pt].sum = ST[2*pt +1].sum + ST[2*pt +2].sum;
        ST[pt].maxm = max(ST[2*pt +1].maxm, ST[2*pt +2].maxm);
        pt = (pt-1)/2;
    }
    
    return;
}

struct stNode query(vector<struct stNode> &ST, int ss, int se, int l, int r, int ind)
{
    //complete overlap
    if (l <= ss && r >= se)
    {
        return ST[ind];
    }
    //no overlap
    if(se < l || ss > r)
    {
        struct stNode temp;
        temp.sum = 0;
        temp.maxm = INT_MIN;
        return temp;
    }
    //partial overlap
    int mid = (ss+se)/2;
    struct stNode leftTree = query(ST, ss, mid, l, r, 2*ind+1);
    struct stNode rightTree = query(ST, mid+1, se, l, r, 2*ind+2);
    struct stNode final;
    final.sum = leftTree.sum + rightTree.sum;
    final.maxm = max(leftTree.maxm, rightTree.maxm);
    return final;
}

int main()
{
    int n, q;
    cin>>n>>q;
    vector<int> vect(n);
    for(int i=0; i<n; i++)
        cin>>vect[i];

    int size = 1;
    while(size < n)
    {
        size *= 2;
    }
    vector<struct stNode> ST(2*size-1);
    for(int i=0; i<2*size-1; i++)
    {
        ST[i].sum = 0;
        ST[i].maxm = INT_MIN;
    }

    buildST(ST, vect, size);

    for(int i=0; i<q; i++)
    {
        int l, r;
        cin>>l>>r;
        struct stNode answer = query(ST, 0, size-1, l, r, 0); //9.2
        int ans = answer.maxm * (r-l+1) - answer.sum;
        cout<<ans<<endl;
    }

    return 0;
}