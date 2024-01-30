 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int dfsRoot,rootChildren,dfsCounter = 1;
 5
 6  vector<vector<int>> table;
 7  vector<int> dfsNum;
 8  vector<int> dfsLow;
 9  vector<int> dfsParent;
10  vector<bool> artiVertices;
11
12  void Articulation_Point_And_Bridge(int a)
13  {
14      dfsNum[a] = dfsLow[a] = dfsCounter++;
15
16      for (int i = 0; i < table[a].size(); ++i)
17      {
18          int b = table[a][i];
19
20          if (dfsNum[b] == 0)
21          {
22              dfsParent[b] = a;
23              if (a == dfsRoot) ++rootChildren;
24              Articulation_Point_And_Bridge(b);
25
26              if (a != dfsRoot && dfsLow[b]>= dfsNum[a])
27                  artiVertices[a] = true;
28              if (dfsLow[b] > dfsNum[a])
29                  cout<<"This is a Bridge : "<<a<<" "<<b<<endl;
30
31              dfsLow[a] = min(dfsLow[a], dfsLow[b]);
32          }
33          else if (b != dfsParent[a])
34              dfsLow[a] = min(dfsLow[a], dfsNum[b]);
35      }
36  }
37
38  int main()
39  {
40      int vertex,edge;
41      while(cin>>vertex>>edge)
42      {
43          table.clear();
44          table.resize(vertex);
45
46          dfsNum.clear();
47          dfsNum.resize(vertex,0);
48
49          dfsLow.clear();
50          dfsLow.resize(vertex,0);
51
52          dfsParent.clear();
53          dfsParent.resize(vertex,0);
54
55          artiVertices.clear();
56          artiVertices.resize(vertex,0);
57
58          for(int i=0; i<edge; i++)
59          {
60              int a,b;
61              cin>>a>>b;
62              table[a].push_back(b);
63              table[b].push_back(a);
64          }
65
66          for (int i = 0; i < table.size(); i++)
67          {
68              if (dfsNum[i] == 0)
69              {
70                  dfsRoot = i;
71                  rootChildren = 0;
72                  Articulation_Point_And_Bridge(i);
73                  if (rootChildren > 1)
74                      artiVertices[dfsRoot] = true;
75              }
76          }
77          cout << count(artiVertices.begin(), artiVertices.end(), true) << endl;
78          for(int i=0; i<artiVertices.size(); i++)
79              if(artiVertices[i]) cout<<i<<endl;
80      }
81  }

