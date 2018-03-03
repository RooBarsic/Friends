# include <bits/stdc++.h>
# define sz(s) int(s.size())
  using namespace std;
  long long arr[10100], sum[10100];
  int main()
  {
    long long n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << '\n';
    }
    return 0;
  }
