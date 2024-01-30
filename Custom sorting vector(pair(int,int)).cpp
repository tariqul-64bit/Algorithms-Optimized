 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  bool comp(pair<int,int> a, pair<int,int> b)
 5  {
 6      if(a.first != b.first) return a.first<b.first;
 7      if(a.first == b.first) return a.second<b.second;
 8      else return true;
 9  }
10
11  int main()
12  {
13      int n;
14      cin>>n;
15      vector<pair<int,int>> P;
16      int a,b;
17
18      for(int i=0; i<n; i++)
19      {
20          cin>>a>>b;
21          P.push_back(make_pair(a,b));
22      }
23
24      sort(P.begin(),P.end(),comp);
25
26      for(int i=0; i<n; i++)
27      {
28          pair<int,int> mypair= P[i];
29          cout<<mypair.first<<" "<<mypair.second<<endl;
30      }
31  }
