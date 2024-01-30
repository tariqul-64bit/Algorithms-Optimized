 1  #include<bits/stdc++.h>
 2  using namespace std;
 3
 4  #define MAX_N 1000  //array size needed is [n+1][w+1] ??
 5  #define MAX_W 1000
 6
 7  int i, N, MW, V[MAX_N], W[MAX_N], memo[MAX_N][MAX_W];
 8
 9  int value(int id, int w)
10  {
11      if (id == N || w == 0) return 0;
12      if (memo[id][w] != -1) return memo[id][w];
13      if (W[id] > w)         return memo[id][w] = value(id + 1, w);
14      return memo[id][w] = max(value(id + 1, w), V[id] + value(id + 1, w - W[id]));
15  }
16
17  int main()
18  {
19      int ans =0;
20      memset(memo, -1, sizeof memo);
21      scanf("%d", &N);
22      for (i = 0; i < N; i++)
23          scanf("%d %d", &V[i], &W[i]);
24
25      scanf("%d", &MW);
26      ans=value(0, MW);
27      printf("%d\n", ans);
28      return 0;
29  }
