/*ou are given a string s and an array of strings words of the same length.
 Return all starting indices of substring(s) in s that is a concatenation of 
 each word in words exactly once, in any order, and without any intervening characters.
You can return the answer in any order.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(unordered_map<string, int> hash, string current, int wordSize){
        for(int i = 0; i < current.size(); i += wordSize){
            string word = current.substr(i, wordSize);
            
            if(!hash[word]) return false;
            hash[word]--;
        }
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = words[0].size() * words.size();
        vector<int> result;
        unordered_map<string, int> hash;
        
        if(s.size() < size) return {};
    
        for(string word : words) hash[word]++;
        
        for(int i = 0; i <= s.size() - size; i++){
            if(check(hash, s.substr(i, size), words[0].size()))
                result.push_back(i);
        }
        
        return result;
    }
};