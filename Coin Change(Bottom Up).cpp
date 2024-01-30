 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int main()
 5  {
 6      int n,i,target;
 7      cin>>n;
 8      int arr[n];
 9      for(i=0; i<n; i++) cin>>arr[i];
10      cin>>target;
11      int table[target+1][n];
12      memset(table,0,sizeof(table));
13
14      for (i = 0; i < n; i++)
15          table[0][i] = 1;
16
17      int j;
18      for (i = 1; i < target + 1; i++)
19      {
20          for (j = 0; j<n; j++)
21          {
22              if((i-arr[j])>= 0) table[i][j] += table[i - arr[j]][j];
23              if(j >= 1) table[i][j] += table[i][j - 1];
24          }
25      }
26      cout << table[target][n - 1];
27  }
