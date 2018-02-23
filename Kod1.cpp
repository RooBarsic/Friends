# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  struct node{
      string s;
      int k;
      bool operator < (const node a) const{
          if(s[1] < a.s[1]) return 1;
          return 0;
      }
  }e;
  multiset< node > st;
  int main()
  {
      int n, k;
      string s;
      cin >> n;
      for(int i = 1; i <= n; i++){
        cin >> s >> k;
        e.s = s;
        e.k = k;
        st.insert(e);
      }
      for(auto a : st){
        cout << a.s << " " << a.k << '\n';
      }
      return 0;
  }
