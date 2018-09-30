#include <bits/stdc++.h>
  using namespace std;
  int arr[10100], brr[10100];
  int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
      cin >> arr[i];
    }
    for(int i = 1; i <= m; i++){
      cin >> brr[i];
    }
    int x = 1;
    for(int i = 1; i <= m; i++){
      while((x <= n) && (arr[x] < brr[i])){
        x++;
      }
      if(x > n) cout << "NO" << '\n';
      else if(arr[x] == brr[i]) cout << x << '\n';
      else cout << "NO" << '\n';
    }
    return 0;
  }
