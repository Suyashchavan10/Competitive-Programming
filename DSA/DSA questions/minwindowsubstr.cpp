/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that
 every character in t (including duplicates) is included in the window.
 If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.
A substring is a contiguous sequence of characters within the string.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool fine(vector<int>& occ,vector<int>& occ2){
        for(int i=0;i<100;i++){
            if(occ[i] > occ2[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> occ(100,0);
        for(char c: t){
            occ[c-'A']++;
        }
        int i = 0,j = 0;
        vector<int> occ2(100,0);
        int best = 1e9, start = -1,end = -1;
        while(j < s.size()){
            occ2[s[j]-'A']++;
            while(fine(occ,occ2)){
                int len = j-i+1;
                if(len < best){
                    best = len;
                    start = i;
                    end = j;
                }
                occ2[s[i]-'A']--;
                i++;
            }
            j++;
        }
        if(best == 1e9){
            return "";
        }
        string ans = "";
        for(int i = start;i<end+1;i++){
            ans.push_back(s[i]);       
        }
        return ans;
    }
};