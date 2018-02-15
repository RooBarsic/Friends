# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  bool isPalindrom(string s;)
  {
      int le = 0, ri = sz(s) - 1;
      while(le < ri){
        if(s[le] != s[ri]) return 0;
        le++;
        ri--;
      }
      return 1;
  }
  int main()
  {
      vector< string > brr, crr;




      crr = isPalindrom(brr, 6);
      return 0;
  }
/**
*/
