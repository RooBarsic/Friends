# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  int days[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector< string > tasks[40];
  int main()
  {
      long long n, x, m;
      cin >> n;
      m = 1;
      for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if(s == "ADD"){
            cin >> x >> s;
            tasks[x].push_back(s);
        }
        else if(s == "NEXT"){
            int nextm = (m % 12) + 1;
            for(int d = days[nextm]; d > days[m]; d--){
                tasks[d].clear();
            }
            for(int d = days[nextm] + 1; d <= days[m]; d++){
                tasks[days[nextm]].insert(tasks[days[nextm]].end(), tasks[d].begin(), tasks[d].end());
            }
            m = nextm;
        }
        else {
            cin >> x;
            cout << tasks[x].size() << " ";
            for(string task : tasks[x]){
                cout << task << " ";
            }
            cout << '\n';
        }
      }
      return 0;
  }
/**

*/
