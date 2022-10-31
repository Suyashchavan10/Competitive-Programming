#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x, y;
    vector<pair<int, int> > plane;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        plane.push_back({x, y});
    }
    sort(plane.begin(), plane.end());
    int counter = 0;
    vector<pair<int, int> > :: iterator it;
    for(it=plane.begin()+1;it!=plane.end();it++)
    {
        if(it->first == (it-1)->first)
        {
            plane.erase(it);
            counter++;
        }
    }
    vector<int> prefix;
    prefix.push_back(plane[0].second);
    for(int i=1;i<plane.size();i++)
    {
        if(plane[i].second < plane[i-1].second)
            prefix.push_back(plane[i].second);
        else
            prefix.push_back(prefix[i-1]);
    }
    for(int i=1; i<plane.size(); i++)
    {
        if(prefix[i-1] <= plane[i].second)
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}