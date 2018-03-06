# include <bits/stdc++.h>
# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
# define sz(s) int(s.size())
  using namespace std;
  int main()
  {
    long long a, b;
    cin >> a >> b;
    while((a != 0) && (b != 0)){
      a = a % (2 * b);
      b = b % (2 * a);
    }
    cout << a << " " << b;
      
      return 0;
  }
