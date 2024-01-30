 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int main()
 5  {
 6      int vertex,edge;
 7      cin>>vertex>>edge;
 8      vector<int> adjList[vertex+1];
 9
10      int indegree[vertex+1];
11      memset(indegree, 0, sizeof(indegree));
12
13      int a,b;
14      for(int i=0; i<edge; i++)
15      {
16          cin >>a>>b;
17          adjList[a].push_back(b);
18          ++indegree[b];
19      }
20
21      queue<int> q;
22      vector<int> solution;
23
24      for(int i = 0; i < vertex; i++)
25      {
26          if(indegree[i] == 0) q.push(i);
27      }
28
29      while(!q.empty())
30      {
31          a = q.front();
32          q.pop();
33          solution.push_back(a);
34
35          for(int i = 0; i < adjList[a].size(); i++)
36          {
37              b = adjList[a][i];
38              --indegree[b];
39              if(indegree[b] == 0) q.push(b);
40          }
41      }
42
43      for(int i = 0; i < vertex; ++i)
44      {
45          cout <<solution[i]<<endl;
46      }
47  }

