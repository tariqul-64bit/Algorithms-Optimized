 1  #include<bits/stdc++.h>
 2  #include<limits.h>
 3  using namespace std;
 4
 5  int subrect, maxsubrect ;
 6  int A[10][10];
 7
 8
 9  int area(int x1,int y1,int x2,int y2)
10  {
11      return (x2-x1+1)*(y2-y1+1);
12  }
13
14  int main()
15  {
16      int n,m;
17      cin>>n>>m;
18      for(int i=0; i<n; i++)
19          for(int j=0; j<m; j++)
20          {
21              cin>>A[i][j];
22              if(j>0) A[i][j]+=A[i][j-1];
23          }
24
25      maxsubrect = INT_MIN;
26
27      int r,l,row;
28      int x1,y1,x2,y2,tempy1;
29
30      for(int l=0; l<m; l++)
31          for(int r=l; r<m; r++)
32          {
33              subrect = 0;
34              for(row=0; row<n; row++)
35              {
36                  if(l>0) subrect+= A[row][r]- A[row][l-1];
37                  else subrect+= A[row][r];
38
39                  if(subrect<0)
40                  {
41                      subrect=0;
42                      tempy1 =row+1;
43
44                  }
45                  if(subrect>maxsubrect)
46                  {
47                      maxsubrect = subrect;
48                      x1=l;
49                      x2=r;
50                      y2=row;
51                      y1= tempy1;
52                  }
53              }
54          }
55      cout<<maxsubrect<<endl;
56      cout<<x1<<y1<<x2<<y2<<endl;
57      cout<<area(x1,y1,x2,y2);
58  }

