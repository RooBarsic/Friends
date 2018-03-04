# include <bits/stdc++.h>
# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
# define sz(s) int(s.size())
  using namespace std;
  int main()
  {
      //IoS;
      //freopen("test.cpp", "r", stdin);
      long long n, a, b, k, t, le, ri, mi;
      cin >> n >> a >> b;
      if(a > b) swap(a, b);
      k = 0;
      while((1 << k) != n){
        k++;
      }
      t = k;
      le = 1;
      ri = n;
      while(le < ri){
        mi = (le + ri) / 2;
        if((le <= a) && (a <= mi) && (mi < b) && (b <= ri)){
            if(t == k) cout << "Final!";
            else cout << k;
            return 0;
        }
        if(b <= mi) ri = mi;
        else le = mi;
        k--;
      }
      return 0;
  }
