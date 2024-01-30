 1 #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  vector<vector<int>> table(100);
 5  int visited[100];
 6  queue<int> q;
 7
 8
 9  void bfs(int vertex)
10  {
11      cout<<vertex<<" ";
12      visited[vertex]=1;
13
14      for(int ii=0; ii<table[vertex].size(); ii++)
15      {
16          if(visited[table[vertex][ii]] == 0) q.push(table[vertex][ii]);
17      }
18  }
19
20
21  int main()
22  {
23      int edges,source;
24      cin>>edges;
25      for(int i=1 ; i<=edges; i++)
26      {
27          int a,b;
28          cin>>a>>b;
29          table[a].push_back(b);
30          table[b].push_back(a);
31      }
32
33      memset(visited,0,sizeof visited);
34      cin>>source;
35      q.push(source);
36      while(!q.empty())
37      {
38          bfs(q.front());
39          q.pop();
40      }
41
42  }

