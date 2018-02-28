# include <bits/stdc++.h>
  using namespace std;
  long long pi = 1000000000ll + 7ll;
  long long dist[100100];
  int color[100100];
  vector< pair< int, long long > > vrr[100100];
  int main()
  {
      freopen("test.cpp", "r", stdin);
      long long n, s, t, x;
      cin >> n >> s >> t;
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x != -1) vrr[i].push_back({j, x});
        }
      }
      for(int i = 1; i <= n; i++){
        dist[i] = pi;
      }
      dist[s] = 0;
      for(int i = 1; i <= n; i++){
        x = -1;
        for(int j = 1; j <= n; j++){
            if(color[j] == 0){
                if((x == -1) || (dist[x] > dist[j])) x = j;
            }
        }
        if((x == -1) || (dist[x] == pi) || (x == t)) break;
        color[x] = 1;
        for(auto v : vrr[x]){
            dist[v.first] = min(dist[v.first], dist[x] + v.second);
        }
      }
      if(dist[t] == pi) cout << "-1"; //cout << " No way from s to t! ";
      else cout << dist[t];
      return 0;
  }
/**
Chekanov Denis
*/
