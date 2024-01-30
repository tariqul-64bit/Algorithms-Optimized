 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int discovered[100];
 5  vector<vector<int> > adjList(100+1);
 6  vector<int> topoSort;
 7
 8  void dfs(int a)
 9  {
10      discovered[a] = true;
11      for(unsigned i = 0; i < adjList[a].size(); ++i)
12      {
13          int b = adjList[a][i];
14          if(!discovered[b]) dfs(b);
15      }
16      topoSort.push_back(a);
17  }
18
19  int main()
20  {
21      int vertex,edge;
22      cin >>vertex>>edge;
23
24      memset(discovered,0,sizeof discovered);
25
26      int a,b;
27      for(int i=0; i<edge; i++)
28      {
29          cin >>a>>b;
30          adjList[a].push_back(b);
31      }
32
33      for(int i = 0; i <= vertex; i++)
34      {
35          if(!discovered[i]) dfs(i);
36      }
37
38
39      for(int i = vertex-1; i >= 0; i--)
40      {
41          cout << topoSort[i]<<endl;
42      }
43  }

