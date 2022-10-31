#include<bits/stdc++.h>
using namespace std;
long long int merge(int arr[], int left, int mid, int right)
{
    long long int mergeinv = 0;
    int leftsz = mid - left + 1;
    int rightsz = right - mid;
    int leftarr[leftsz], rightarr[rightsz];
    for(int i=0;i<leftsz;i++)
        leftarr[i] = arr[left+i];
    for(int i=0;i<rightsz;i++)
        rightarr[i] = arr[mid+i+1];
    int i = 0, j = 0, k = left;
    while(i<leftsz && j<rightsz)
    {
        if(leftarr[i] <= rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while(i < leftsz)
    {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while(j < rightsz)
    {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
    return mergeinv;
}
long long int mergeinversion(int arr[], int left, int right)
{
    long long int inv = 0;
    if(left < right)
    {
        int mid = (left+right)/2;
        inv += mergeinversion(arr, left, mid);
        inv += mergeinversion(arr, mid+1, right);
        inv += merge(arr, left, mid, right);
    }
    return inv;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<mergeinversion(arr, 0, n-1);
    return 0;
}
