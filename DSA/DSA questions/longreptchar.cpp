#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0, maxRepeating = 0, maxLen = 0;
        unordered_map<char, int> m;
        
        //Character other than maximum repeating character should at most be k, becuase we can make only k changes in the string.
        //(length of substring - number of times of the maximum occurring character in the substring) <= k
		
        for(j=0; j<s.size(); j++){
            m[s[j]]++;
            maxRepeating = max(maxRepeating, m[s[j]]);
            //When other characters become greater than k, we move window ahead.
            if(j-i+1 - maxRepeating > k){
                m[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};