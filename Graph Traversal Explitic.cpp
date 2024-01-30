 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  vector<string> grid;                //to store the input
 5  bool visited[100][100];            // to check whether this node is visited or not
 6  string z;                         // to take input row as strings
 7  int row,column;
 8  int no_of_components;               //total number of components
 9  int max_sized_component;           //maximum size component exist in the grid
10  int temp_size;                    //to store current component size
11  vector<int> size_list;           // to store all the component sizes
12
13  void floodfill(int r,int c)
14  {
15      if(r<0 || c<0 || r>=row || c>= column) return;          //out of bound
16      if(visited[r][c]) return;                              //previously visited
17      if(grid[r][c] == '0') return;                         //empty field
18
19      visited[r][c] = 1;                                  //mark current nood as visited
20      temp_size++;
21
22      floodfill(r+1,c);                                 // 8 way traversing
23      floodfill(r-1,c);
24      floodfill(r,c+1);
25      floodfill(r,c-1);
26      floodfill(r+1,c+1);
27      floodfill(r+1,c-1);
28      floodfill(r-1,c-1);
29      floodfill(r-1,c-1);
30  }
31
32  int main()
33  {
34      while(getline(cin,z) && z.size() && z[0]!='\n')    //taking input,double press
35      {                                                 //enter to abort inputting
36          grid.push_back(z);
37      }
38
39      column = grid[0].size();                          //determine row & column size
40      row = grid.size();
41
42      memset(visited,false,sizeof(visited));            //haven't visited any node yet
43
44      for(int i=0; i<row; i++)                          //FLOODFILL
45          for(int j=0; j<column; j++)
46          {
47              if(!visited[i][j]  && grid[i][j] == '1')
48              {
49                  floodfill(i,j);
50                  no_of_components++;
51                  size_list.push_back(temp_size);
52                  if(temp_size>max_sized_component) max_sized_component=temp_size;
53                  temp_size=0;
54              }
55          }
56                                                      //Output all the properties
57      cout<<"No of Connected Components "<<no_of_components<<endl;
58      cout<<"Maximum Sized Components "<<max_sized_component<<endl;
59      for(auto it=size_list.begin(); it!=size_list.end(); ++it)
60      {
61          cout<<*it<<endl;
62      }
63                                               //If needed size of a component which goes
64                                                  //through a specific point xx,yy
65                                                  //negative number to break this cycle
66      int xx,yy;
67      while(cin>>xx && cin>>yy && xx>=0 && yy>=0)
68      {
69          memset(visited,0,sizeof visited);
70          temp_size=0;
71          floodfill(xx,yy);
72          cout<<temp_size<<endl;
73      }
74  }

