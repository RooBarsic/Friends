# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  int getpos(int x, int y){
      if(x == y) return 0;
      if(x > y) return 1;
      if(x < y) return 2;
  }
  int main()
  {
      long long n, ans, x, y, x2, x3, y2, y3;
      string s;
      cin >> n >> s;
      x = y = 0;
      x2 = y2 = x3 = y3 = 0;
      ans = 0;
      for(int i = 0; i < n; i++){
        x3 = x2;
        y3 = y2;
        x2 = x;
        y2 = y;
        if(s[i] == 'U') y++;
        else x++;
        if(i >= 2){
            if((getpos(x, y) == 1) && (getpos(x3, y3) == 2)) ans ++;
            else if((getpos(x, y) == 2) && (getpos(x3, y3) == 1)) ans++;
        }
      }
      cout << ans;
      return 0;
  }
