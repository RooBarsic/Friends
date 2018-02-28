/// Ne Visman
# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  int arr[10010][10010], color[100100];
  pair< int, int > brr[100100];
  vector< int > vrr;
  int cmp(pair< int, int > a, pair< int, int > b){
      if(color[a.second] != 0) return 0;
      if((color[a.second] == 0) && (color[b.second] != 0)) return 1;
      if(a.first > b.first) return 1;
      return 0;
  }
  int main(){
      freopen("test.cpp", "r", stdin);
      long long n, kola, k;
      cin >> n;
      for(int i = 1; i <= n; i++){
        brr[i].second = i;
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if((i < j) && (arr[i][j] > 0)){
                brr[i].first++;
                brr[j].first++;
            }
        }
      }
      kola = 0;
      k = 0;
      while(kola < n){
          sort(brr + 1, brr + 1 + n, cmp);
          int v = brr[1].second;
          if(color[v] != 0) break;
          k++;
          kola++;
          vrr.clear();
          vrr.push_back(v);
          color[v] = k;
          for(int i = 2; i <= n; i++){
            int x = brr[i].second;
            if(color[x] != 0) break;
            int f = 1;
            for(int g : vrr){
                if(arr[g][x] != 0){
                    f = 0;
                    break;
                }
            }
            if(f == 1){
                vrr.push_back(x);
                color[x] = k;
                kola++;
            }
          }
          for(int g : vrr){
            for(int i = 1; i <= n; i++){
                if(arr[g][i] > 0){
                    arr[g][i] = 0;
                    arr[i][g] = 0;
                    brr[i].first--;
                    brr[g].first--;
                }
            }
          }
      }
      cout << k << '\n';
      for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
      }
      return 0;
  }
