# include <bits/stdc++.h>
  using namespace std;
  int n, m;
  string srr[110];
  string buf;
  vector< string > vrr;
  void way(int x, int y, int id){
      buf[id] = srr[x][y];
      if((x == n) && (y == m)){
          vrr.push_back(buf);   
          return ;
      }
      if(x < n) way(x + 1, y, id + 1);
      if(y < m) way(x, y + 1, id + 1);
  }
  void solve(){
      int k;
      cin >> n >> m;
      buf = "";
      for(int i = 1; i <= n; i++){
          cin >> srr[i];
          if(i < n) buf += "1";
      }
      buf += srr[1];
      cin >> k;
      m--;
      way(1, 0, 0);
      sort(vrr.begin(), vrr.end());
      cout << vrr[k - 1];
  }
  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
      int k = 1;
      while(k > 0){
          k--;
          solve();
          cout << '\n';
      }
      return 0;
  }
