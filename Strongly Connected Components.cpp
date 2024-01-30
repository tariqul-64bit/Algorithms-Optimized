 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  vector<vector<int>> table;
 5  vector<int> dfsNum, dfsLow, S;
 6  vector<bool> visited;
 7  int numSCC,dfsNumberCounter;
 8
 9  void tarjanSCC(int a)
10  {
11      dfsLow[a] = dfsNum[a] = dfsNumberCounter++;
12      S.push_back(a);
13      visited[a] = 1;
14
15      for (int i = 0; i < table[a].size(); i++)
16      {
17          int x = table[a][i];
18
19          if (dfsNum[x] == -1)
20              tarjanSCC(x);
21          if (visited[x])
22              dfsLow[a] = min(dfsLow[a], dfsLow[x]);
23      }
24
25      if (dfsLow[a] == dfsNum[a])
26      {
27          printf("SCC %d:", ++numSCC);
28          while (1)
29          {
30              int p = S.back();
31              S.pop_back();
32              visited[p] = 0;
33              cout<<" "<<p;
34              if (a == p) break;
35          }
36          printf("\n");
37      }
38  }
39
40  int main()
41  {
42      int vertex,edge;
43      while(cin>>vertex>>edge)
44      {
45          table.clear();
46          table.resize(vertex);
47
48          dfsNum.assign(vertex, -1);
49          dfsLow.assign(vertex, 0);
50          visited.assign(vertex, 0);
51
52          dfsNumberCounter = numSCC = 0;
53
54          int a,b;
55          for(int i=0; i<edge; i++)
56          {
57              cin>>a>>b;
58              table[a].push_back(b);
59          }
60          for (int i = 0; i < vertex; i++)
61              if (dfsNum[i] == -1)
62                  tarjanSCC(i);
63      }
64  }
