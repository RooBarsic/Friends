# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  int pred[100100], kol[100100];
  vector< pair< int, long long > > vrr[100100];
  vector< pair< long long, pair< int, int > > > roads;
  int find_pred(int v){
      if(pred[v] == v) return v;
      return pred[v] = find_pred(pred[v]);
  }
  void union_ab(int a, int b){
      a = find_pred(a);
      b = find_pred(b);
      if(a != b){
        if(kol[a] < kol[b]) swap(a, b);
        while(sz(vrr[b]) > 0){
            vrr[a].push_back(vrr[b].back());
            vrr[b].pop_back();
        }
        pred[b] = a;
        kol[a] += kol[b];
      }
  }
  void union_all(long long p){
      while((sz(roads) > 0) && (roads.back().first >= p)){
        union_ab(roads.back().second.first, roads.back().second.second);
        roads.pop_back();
      }
  }
  void go(){
      long long n, s, t, x, plank, m;
      cin >> n >> s >> t;
      for(int i = 1; i <= n; i++){
        pred[i] = i;
        kol[i] = 1;
      }
      /**
      for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vrr[a].push_back({b, c});
        vrr[b].push_back({a, c});
        roads.push_back({c, {a, b}});
      }
      */
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if((x > -1) && (i < j)){
                vrr[i].push_back({j, x});
                vrr[j].push_back({i, x});
                roads.push_back({x, {i, j}});
            }
        }
      }
      sort(roads.begin(), roads.end());
      plank = 1000000000000ll;
      while(find_pred(s) != find_pred(t)){
        int v = find_pred(s);
        x = -1;
        for(auto to : vrr[v]){
            if((to.second < plank) && ((x == -1) || (x < to.second))) x = to.second;
        }
        plank = x;
        union_all(plank);
      }
      cout << plank;
  }
  int main()
  {
      freopen("test.cpp", "r", stdin);
      int t = 1;
      while(t > 0){
        go();
        cout << '\n';
        t--;
      }
      return 0;
  }
