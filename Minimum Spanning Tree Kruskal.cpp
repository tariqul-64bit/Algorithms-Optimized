#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,int> PII;
vector<PII> adj[10000];
bool marked[10000];

long long prim(int x)
{
    long long minimumcost= 0;
    priority_queue<PII,vector<PII>,greater<PII> > Q;
    PII p;
    Q.push(make_pair(0,x));

    while(!Q.empty())
    {
        p=Q.top();
        Q.pop();
        int x;
        x=p.second;
        if(marked[x] == true) continue;
        marked[x]= true;
        minimumcost += p.first;

          for(int i = 0; i < adj[x].size(); ++i)
        {
            if(marked[adj[x][i].second] == false)
                Q.push(adj[x][i]);
        }

    }
return minimumcost;
}


int main()
{
    memset(marked,false,sizeof(marked));
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        int x,y,weight;
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));


    }


    cout<<prim(1)<<endl;

}
