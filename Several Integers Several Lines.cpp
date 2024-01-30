 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int main()
 5  {
 6      string s;
 7      while(getline(cin,s))
 8      {
 9          if(!s.size()) continue; //to avoid \n character at end of each line
10
11          cout<<"Following integers in  line:"<<endl;
12          stringstream ss(s);
13          int a;
14          while(ss>>a)
15          {
16              cout<<a<<endl;
17          }
18      }
19  }

