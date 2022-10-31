#include<bits/stdc++.h>
using namespace std;
void
MaxBottomupheapify (int H[], int i)
{
  int p = (i - 1) / 2, t;
  int temp;

  while (p > -1)
    {
      if (H[i] > H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
MaxTopdownheapify (int H[], int i, int n)
{
  int c, t,temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] > H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] < H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] < H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      i = c;
    }

}

void
MaxAdd (int H[], int X, int *n)
{

  H[*n] = X;
  *n = *n + 1;

  MaxBottomupheapify (H, *n - 1);
}

void
DeleteMax (int H[], int *n)
{
  int t;
  
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  MaxTopdownheapify (H, 0, *n);
}

void
MaxBuildHeap (int H[],  int n)
{

  int i = n / 2;
  while (i > -1)
    {
      MaxTopdownheapify (H, i--, n);
    }

}

void
Bottomupheapify (int H[],  int i)
{
  int p = (i - 1) / 2, temp;

  while (p > -1)
    {
      if (H[i] < H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
Topdownheapify (int H[],  int i, int n)
{
  int c, temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] < H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] > H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] > H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
    }

}

void
Add (int H[], int X, int *n)
{

  H[*n] = X;
  *n = *n + 1;

  Bottomupheapify (H, *n - 1);
}

void
DeleteMin (int H[],  int *n)
{
  
  int t;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  Topdownheapify (H,0,*n);
}

void
BuildHeap (int H[],  int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, i--, n);

    }

}

void
DecreaseKey (int H[],  int i, int X)
{

  H[i] = X;

  Bottomupheapify (H, i);


}

void
IncreaseKey (int H[],  int i, int X)
{

  H[i] = X;

  MaxBottomupheapify (H, i);


}

void
HeapSort (int H[],  int n)
{

  int m=n,i;
  BuildHeap(H,n);
  for(i=0;i<n;++i) DeleteMin(H,&m);

  for(i=0;i<n-1;++i) if(H[i]<H[i+1]) cout<<"Problem";

}

int main()
{
    int H[60000],i,j,n;
    cin>>n;
    for(i=0;i<n;++i) H[i]=32000-rand()%61234;

    HeapSort(H,n);
    return 0;
}


