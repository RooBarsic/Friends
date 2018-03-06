# include <bits/stdc++.h>
# define IoS ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
# define sz(s) int(s.size())
  using namespace std;
  int main()
  {
    long long a, b, aa, bb;
    cin >> a >> b;
    while((a != 0) && (b != 0)){
      aa = a; bb = b;
      a = a % (2 * b);
      if(a != 0) b = b % (2 * a);
      if((a == aa) && (b == bb)) break;
    }
    cout << a << " " << b;
      
      return 0;
  }
