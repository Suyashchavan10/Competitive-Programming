// finding length of longest substring with equal no.s of zeros and ones.

#include<bits/stdc++.h>
using namespace std;
 
// function zeroOneEqual finds the length of the longest substring
// with equal number of zeros and ones.
int zeroOneEqual(string binstr)
{
    // make a map to store differences of counts of 1s and 0s.
    map<int, int> mymap;
     
    // at the start, difference between both is 0.
    mymap[0] = -1;  
     
    //zeroCount and oneCount keep track of number of zeroes and ones resp.
    int zeroCount = 0, oneCount = 0;
    //answer keep tracks of maximum length.
    int answer = 0;
    //ind variable is working as pointer for travelling over a string.
    int ind;

    //travelling through entire string to count number of ones and zeroes.
    for(ind=0; ind<binstr.size(); ind++)
    {
        if (binstr[ind] == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }

        //if current difference between 2 counts exists previously, then substring between 
        //previous and current index has same.

        // Update answer variable if current substring has maximum length than before.
        if (mymap.find(oneCount - zeroCount) != mymap.end())
        {
            answer = max(ind - mymap[oneCount - zeroCount], answer);
        }
        // If we see this difference first time then store it in mymap.       
        else
        {
            mymap[oneCount - zeroCount] = ind;
        }
    }
    //returning final answer.
    return answer;
}
 
int main()
{
    string binstr01;
    //cin>>binstr01;
    string binstr1 = "1010010100";
    string binstr2 = "1001110000";
    for(int i=0;i<20;i++)
        binstr2 = binstr2 + binstr2;
    cout<<"string 1 = 1010010100 : ";
    cout<<zeroOneEqual(binstr1)<<endl;
    cout<<"answer for string of length 10^6 : ";
    cout<<zeroOneEqual(binstr2)<<endl;
    return 0;
}
