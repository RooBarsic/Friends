# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  string dell_2(string a)
  {
      if(a == "") return "0";
      if(a == "0") return "0";
      long long x = 0;
      string b = "";
      for(int i = 0, kpf = sz(a); i < kpf; i++){
        x = (x * 10) + (int(a[i]) - int('0'));
        if((sz(b) > 0) || (x >= 2)) b += char(int('0') + (x / 2));
        x = x % 2;
      }
      if(b == "") return "0";
      return b;
  }
  string konvert(string w)
  {
      if(w == "") return "";
      if(w == "0") return "0";
      string ans = "";
      while((sz(w) > 1) || (w[0] != '0')){
        if((int(w[sz(w) - 1]) - int('0')) % 2 == 0) ans += "0";
        else ans += "1";
        //cout << " w = was =  " << w << " become to " << dell_2(w) << '\n';
        w = dell_2(w);
      }
      if(ans == "") return "0";
      reverse(ans.begin(), ans.end());
      return ans;
  }
  int main()
  {
      string s, t, res;
      cin >> s;
      t = "";
      res = "";
      for(int i = 0, kpf = sz(s); i < kpf; i++){
        if(('0' <= s[i]) && (s[i] <= '9')) t += s[i];
        else {
            //cout << " i = " << i << " t = " << t << '\n';
            res += konvert(t);
            res += s[i];
            t = "";
        }
      }
      res += konvert(t);
      cout << res;
      return 0;
  }
/**

*/
