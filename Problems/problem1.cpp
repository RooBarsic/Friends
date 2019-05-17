# include <bits/stdc++.h>
  using namespace std;
  inline double rast_kv(double x1, double y1, double x2, double y2){
      return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
  }
  inline double plosh(double x1, double y1, double x2, double y2, double x3, double y3){
      double l1 = sqrt(rast_kv(x1, y1, x2, y2));
      double l2 = sqrt(rast_kv(x1, y1, x3, y3));
      double l3 = sqrt(rast_kv(x2, y2, x3, y3));
      double p = (l1 + l2 + l3) / 2.0;
      double s = sqrt(p * (p - l1) * (p - l2) * (p - l3));
      return s;
  }
  // 1 - inside 0 - not inside
  int check(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3){
      double s1, s2, s3;
      s1 = plosh(x, y, x1, y1, x2, y2);
      s2 = plosh(x, y, x1, y1, x3, y3);
      s3 = plosh(x, y, x2, y2, x3, y3);
      if((s1 == 0) || (s2 == 0) || (s3 == 0)) return 0;
      if(plosh(x1, y1, x2, y2, x3, y3) == s1 + s2 + s3) return 1;
      return 0;
  }
  void solve(){
      int arr[110][3];
      int n;
      cin >> n;
      for(int i = 1; i <= n; i++){
          cin >> arr[i][1] >> arr[i][2];
      }
      for(int x = 1; x <= n; x++){
          for(int y = x + 1; y <= n; y++){
              for(int z = y + 1; z <= n; z++){
                  int flag = 1;
                  for(int i = 1; i <= n; i++){
                      if(check(arr[i][1], arr[i][2], arr[x][1], arr[x][2], arr[y][1], arr[y][2], arr[z][1], arr[z][2]) == 1){
                          flag = 0;
                          break;
                      }
                  }
                  if(flag == 1){
                      cout << "YES";
                      return ;
                  }
              }
          }
      }
      cout << "NO";
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
