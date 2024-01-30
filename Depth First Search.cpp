 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  vector<vector<int>> table(100);
 5  int visited[100];
 6
 7
 8  void dfs(int vertex)
 9  {
10      visited[vertex]=1;
11      cout<<vertex<<" ";
12      for(int ii=0; ii<table[vertex].size(); ii++)
13      {
14          if(visited[table[vertex][ii]] == 0) dfs(table[vertex][ii]);
15      }
16  }
17
18
19  int main()
20  {
21      int edges;
22      cin>>edges;
23      for(int i=1 ; i<=edges; i++)
24      {
25          int a,b;
26          cin>>a>>b;
27          table[a].push_back(b);
28          table[b].push_back(a);
29      }
30      memset(visited,0,sizeof visited);
31      dfs(1);
32  }

