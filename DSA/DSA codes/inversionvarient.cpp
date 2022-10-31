#include <iostream>
using namespace std;

long long int merge(long long int arr[], long long int temp[], int start, int end, int mid)
{
  int i,j,k;
  int count=0;

  i=start, j=mid, k=start;

  while ((i <= mid - 1) && (j <= end)) 
  { 
    if(arr[i] > 2*arr[j]) 
    { 
      temp[k++] = arr[i++]; 
    }

    else
    { 
      temp[k++] = arr[j++]; 
      count = count + (mid - i); 
    } 
  } 
  
  while (i <= mid - 1) 
    temp[k++] = arr[i++]; 

  while (j <= end) 
    temp[k++] = arr[j++]; 

  for (i = start; i <= end; i++) 
    arr[i] = temp[i]; 
  
  return count; 
}

long long int ms(long long int arr[], long long int temp[], int start, int end)
{
  int mid, count=0;

  if(end>start)
  {
    mid = (start+end)/2;

    count += ms(arr, temp, start, mid);
    count += ms(arr, temp, mid+1, end);

    count += merge(arr, temp, start, end, mid+1);
  }

  return count;
}

long long int mergeSort(long long int arr[], int n)
{
  long long int temp[n];
  return ms(arr, temp, 0, n-1);
}