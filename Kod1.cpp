 # include <bits/stdc++.h>
# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
# define sz(s) int(s.size())
  using namespace std;
  int main()
  {
     string s;
     int f = 0:
     cin >> s;
     for(int b = 0, c=sz(s); b < c; b++){
       if(int(s[b]) - int('a') <= f){
         s[b] = char(int('a')+f);
         f++;
       }
       if(f >= 26) break;
     }
     if(f < 26) cout<<"-1";
     else cout << s;
     return 0;
   }


  
