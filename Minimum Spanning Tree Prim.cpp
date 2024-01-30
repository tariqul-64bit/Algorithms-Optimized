#include<bits/stdc++.h>
using namespace std;
int id[10000], nodes, edges;
pair <long long, pair<int, int> > p[10000];

void initialize()
{
for(int i = 0;i < 10000;++i)
id[i] = i;
}

int root(int x)
{
while(id[x] != x)
{
id[x] = id[id[x]];
        x = id[x];
}
return x;
}
n
void union1(int x, int y)
{
int p = root(x);
int q = root(y);
id[p] = id[q];
}


long long kruskal(pair<long long, pair<int, int> > p[])
{
int x, y;
long long cost, minimumCost = 0;

for(int i = 0;i < edges;++i)
{
// Selecting edges one by one in increasing order from the beginning
x = p[i].second.first;
y = p[i].second.second;
cost = p[i].first;
// Check if the selected edge is creating a cycle or not
if(root(x) != root(y))
{


minimumCost += cost;
union1(x, y);
for(int sss=1;sss<=nodes;++sss) cout<<id[sss]<<endl;
cout<<"____";
}
}
return minimumCost;
}




int main()
{
int x, y;
long long weight, cost, minimumCost;
initialize();
cin >> nodes >> edges;
for(int i = 0;i < edges;++i)
{
cin >> x >> y >> weight;
p[i] = make_pair(weight, make_pair(x, y));
}

sort(p, p + edges);
minimumCost = kruskal(p);
cout << minimumCost << endl;
return 0;
}

