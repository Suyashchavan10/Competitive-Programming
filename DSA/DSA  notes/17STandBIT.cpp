
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int PrefixSum(int BIT[], int i)
{
	int sum = 0; // Iniialise sum 


	while (i>0)
	{
		sum += BIT[i];

		i -= i & (-i);
	}
	return sum;
}

void updateBIT(int BIT[], int n, int i, int X)
{

	while (i <= n)
	{
	BIT[i] += X;

	i += i & (-i);
	}
}

int * 
constructBIT(int A[], int n)
{
	int *BIT = new int[n+1];
	for (int i=1; i<=n; i++)
		BIT[i] = 0;

	for (int i=1; i<=n; i++)
		updateBIT(BIT, n, i, A[i]);

	return BIT;
}



 void 
Update (int *ST, int A[], int n, int i, int X) {
  
A[i] = X;
  
i = i + n - 1;
  
int p = (i - 1) / 2;
  while (p > -1)    {
      
 if (A[ST[2 * p + 1]] < A[ST[2 * p + 2]])
	
 ST[p] = ST[2 * p + 1];
      
       else

ST[p] = ST[2 * p + 2];
      
                            p = (p - 1) / 2;

    
        }


}


int 
RMQ1 (int *ST, int A[], int n, int ss, int se, int l, int r, int i) 
{

    // If segment is inside the given range , then return the min of the segment
    if (l <= ss && r >= se) return ST[i];
  

    // If segment of this node is outside the given range
    if (se < l || ss > r) return n;
  
    // If segment overlaps with the given range
  int mid = (ss + se) / 2;
  
int m1 = RMQ1 (ST, A, n, ss, mid, l, r, 2 * i + 1);

int m2 = RMQ1 (ST, A, n, mid + 1, se, l, r, 2 * i + 2);

if (A[m1] < A[m2]) return m1;

  else return m2;

}


 
int 
RMQ (int *ST, int A[], int n, int l, int r) 
{
 
    // Check for erroneous input values
    if (l < 0 || r > n - 1 || l > r)    {
      
 cout << "Invalid Input";
 
return -1;}
  
 return RMQ1 (ST, A, n, 0, n - 1, l, r, 0);

}


int *
constructST (int A[], int n) 
{

int i;
  
int *ST = new int[2 * n - 1];
  
for (i = n - 1; i < 2 * n - 1; ++i)
    
ST[i] = i - n + 1;

i = n - 2;
while (i > -1)    {
      
 if (A[ST[2 * i + 1]] < A[ST[2 * i + 2]])
	
 ST[i] = ST[2 * i + 1];
      
       else

ST[i] = ST[2 * i + 2];
      
i--;
    
}
  
return ST;

}


int 
main () 
{

int A[50000], n, l, r, i, k;

cin >> n;

for (i = 0; i < n; ++i)
    
A[i] = rand () % 4 * n + i;
  
i = 1;
  
while (i < n)i = i * 2;
  
 k = i;
 
while (i > n - 1)    {
      
A[i] = INT_MAX;
      i--;
    }
  
 n = k;
  
A[n] = INT_MAX;
 
 int *ST = constructST (A, n);
 
cin >> l >> r;
 
cout << "RMQ" << l << " and  " << r << " = " << RMQ (ST, A,n,l,r)<<endl;
  
 cin >> i >> k;
 
Update (ST, A, n, i, k);
  
cout << "RMQ" << l << " and  " << r << " = " << RMQ (ST, A,n,l,r)<<endl;
 


  
for (i = 1; i < =n; ++i)
   A[i] = 200 - rand () % 100;
  
	int *BIT = constructBIT(A, n);

cout << " Inpute for PrefixSum";
cin >>i;
	cout << "PrefixSum "<<i<<"is"<< PrefixSum(BIT, i);

	
cout << " Inpute for Update";
cin >>l>>k;
A[l]+=k;
	updateBIT(BIT, n, l, k); 
	
	cout << "PrefixSum "<<i<<"is"<< PrefixSum(BIT, i);


return 0;
}


 
 
 
 
 
 
 
 
 
 
 
 
 





