 1  #include <bits/stdc++.h>
 2  using namespace std;
 3  const int MAX_N = 1010;
 4  const int MAX_W = 40;
 5  int V[MAX_N], W[MAX_N], C[MAX_N][MAX_W];
 6
 7  int main()
 8  {
 9      int N;
10      scanf("%d", &N);
11      for (int i = 1; i<= N; ++i)
12          scanf("%d %d", &V[i], &W[i]);
13      int ans = 0;
14      int MW;
15      scanf("%d", &MW);
16
17      for (int i = 0; i <= N;  ++i) C[i][0] = 0;
18      for (int w = 0; w <= MW; ++w) C[0][w] = 0;
19      for (int i = 1; i <= N; ++i)
20          for (int w = 1; w <= MW; ++w)
21          {
22              if (W[i] > w) C[i][w] = C[i-1][w];
23              else          C[i][w] = max(C[i-1][w], V[i] + C[i-1][w-W[i]]);
24          }
25
26      ans = C[N][MW];
27      printf("%d\n", ans);
28      return 0;
29  }

