 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  int main()
 5  {
 6      string S;
 7      cin>>S;
 8      sort(S.begin(),S.end());
 9      do
10      {
11          cout<<S<<endl;
12      }
13      while(next_permutation(S.begin(),S.end()));
14  }
