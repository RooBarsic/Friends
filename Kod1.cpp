# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  bool isPalindrom(string s)
  {
      int le = 0, ri = sz(s) - 1;
      while(le < ri){
        if(s[le] != s[ri]) return 0;
        le++;
        ri--;
      }
      return 1;
  }
  vector< string > PalindromFilter(vector< string > word, int minLength)
  {
      vector< string > ans;
      for(int i = 0; i < sz(word); i++){
        if((isPalindrom(word[i]) == 1) && (sz(word[i]) >= minLength)) ans.push_back(word[i]);
      }
      return ans;
  }
  int main()
  {
      int n, mLen;
      vector< string > arr, brr;
      cin >> n >> mLen;
      for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        arr.push_back(s);
      }
      brr = PalindromFilter(arr, mLen);
      for(int i = 0; i < sz(brr); i++){
        cout << brr[i] << " ";
      }
      return 0;
  }
/**
*/
