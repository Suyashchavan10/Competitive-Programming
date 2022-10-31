/*Given a string s, find the length of the longest substring without repeating characters.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt=0,res=0;
        string a;
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;
        for(int i=0;i<s.size();i++){
            int b=s[i];
            if(a.find(b) != string::npos){
                while(a.find(b)!= string::npos){
                    a.erase(a.begin());
                }
                a+=s[i];
                if(s.size()==1)
                    cnt=1;
                else
                    cnt=a.size();
            }
            else{
                a+=s[i];
                cnt++;
                res=max(res,cnt);
            }
        }
        return res;
    }
};