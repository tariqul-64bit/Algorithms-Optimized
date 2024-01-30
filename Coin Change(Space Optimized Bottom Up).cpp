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
11      int table[target+1];
12      memset(table,0,sizeof table);
13      table[0] = 1;
14
15      int j;
16      for(i=0; i<n; i++)
17          for(j=arr[i]; j<=target; j++)
18              table[j] += table[j-arr[i]];
19
20      cout<<table[target]<<endl;
21  }

