/*Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int> st;
        
        st.push(-1);
        int result=0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(!st.empty()){
                    result=max(result,i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return result;
    }
};