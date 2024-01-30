 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int main()
 5  {
 6      bool bipartile=true;
 7      vector<vector<int>> table(100);
 8      int color[100];
 9
10      memset(color,-1,sizeof color);
11
12      int vertex,edge;
13      cin>>vertex>>edge;
14      int a,b;
15      for(int i=0; i<edge; i++)
16      {
17          cin>>a>>b;
18          table[a].push_back(b);
19          table[b].push_back(a);
20      }
21
22      queue<int> q;
23      q.push(0);
24      color[0]= 1;
25
26      while(!q.empty() && bipartile)
27      {
28          int x=q.front();
29          q.pop();
30
31          for(int i=0; i<table[x].size() && bipartile; i++)
32          {
33              if(color[table[x][i]] == -1 )
34              {
35                  if(color[x] == 1) color[table[x][i]] =0;
36                  else color[table[x][i]] =1;
37
38                  q.push(table[x][i]);
39              }
40              else if(color[x] == color[table[x][i]])
41              {
42                  bipartile=false;
43                  break;
44              }
45          }
46      }
47
48      bipartile ? cout<<"Bicolorable"<<endl : cout<<"Not Bicolorable"<<endl;
49  }
50

