 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int config[100][8];
 5  int temp_config[8];
 6  int counter=0;
 7
 8  bool canplace(int x,int y)
 9  {
10      for(int i=0; i<y; i++)
11          if( temp_config[i] == x || (abs(temp_config[i] - x) == abs(i-y)))
12              return false;
13      return true;
14  }
15
16  backtracker(int c)
17  {
18      if(c==8)
19      {
20          for(int i =0; i<8; i++)
21          {
22              config[counter][i] = temp_config[i];
23          }
24          counter++;
25      }
26
27      for(int rows =0; rows<8; rows++)
28      {
29          if(canplace(rows,c))
30          {
31              temp_config[c] = rows;
32              backtracker(c+1);
33          }
34      }
35  }
36
37  int main()
38  {
39      memset(config,-1,sizeof(config));
40      memset(temp_config,0,sizeof(temp_config));
41
42      backtracker(0);
43
44      for(int i=0; i<99; i++,cout<<endl)
45      {
46          cout<<"Config no. "<<i+1<<": == ";
47
48          for(int j=0; j<8; j++)
49          {
50              cout<<config[i][j]+1<<" ";
51          }
52      }
53  }
