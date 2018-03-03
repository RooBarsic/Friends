# include <bits/stdc++.h>
# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
# define sz(s) int(s.size())
  using namespace std;
  int main()
  {
      int k;
      string s;
      getline(cin, s);
      s += " ";
      k = 0;
      for(int i = 1, kpf = sz(s); i < kpf; i++){
        if((s[i - 1] != ' ') && (s[i] == ' ')) k++;
      }
      cout << k;
      return 0;
  }
