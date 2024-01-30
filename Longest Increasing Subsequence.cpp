 1  #include<bits/stdc++.h>
 2  using namespace std;
 3  #define maxn 10000
 4
 5  int main()
 6  {
 7
 8      int n,i;
 9      cin>>n;
10      int A[maxn],L[maxn],L_id[maxn],P[maxn];
11
12      for(i=0; i<n; i++) cin>>A[i];
13
14      int lis=0, lis_end = 0;
15      for( i=0; i<n; i++)
16      {
17
18          int pos = lower_bound(L,L+lis,A[i])-L;
19          L[pos]=A[i];
20          L_id[pos] = i;
21
22          if(pos==0) P[i]=-1;
23          else P[i]=L_id[pos-1];
24
25          if(pos+1>lis)
26          {
27              lis=pos+1;
28              lis_end = i;
29          }
30
31      }
32
33  cout<<lis<<endl;
34
35  int printer = lis_end;
36  stack<int> s;
37  while(P[printer] >= 0)
38  {
39      s.push(A[printer]);
40      printer=P[printer];
41  }
42
43  cout<<A[printer];
44
45  while(!s.empty())
46  {
47      cout<<s.top();
48      s.pop();
49  }
50
51
52  }
