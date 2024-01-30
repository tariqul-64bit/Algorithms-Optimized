 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int n,target, arr[15], memo[15][10000];
 5
 6  int ways(int type, int value)
 7  {
 8      if (value == 0)              return 1;
 9      if (value < 0 || type == n)  return 0;
10      if (memo[type][value] != -1) return memo[type][value];
11      return memo[type][value] = ways(type + 1, value) + ways(type, value - arr[type]);
12  }
13
14  int main()
15  {
16      memset(memo, -1, sizeof memo);
17      cin>>n;
18      for(int i=0; i<n; i++) cin>>arr[i];
19      cin>>target;
20      cout<<ways(0, target);
21  }

