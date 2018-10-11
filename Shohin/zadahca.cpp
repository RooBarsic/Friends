# include <bits/stdc++.h>
  using namespace std;
  int main()
  {
      int n, k;
      cin >> n >> k;
      int arr[n + 1][n + 1];
      for(int i = 1; i <= n; i++){
          arr[i][0] = arr[0][i] = 0;
      }
      for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
              arr[i][j] = ( k * k );
              arr[0][j] += arr[i][j];
              arr[i][0] += arr[i][j];
              k++;
          }
      }
      for(int i = 1; i <= n; i++){
          for(int j = 1; j <= n; j++){
              cout << arr[i][j] << " ";
          }
          cout << arr[i][0] << " ";
          cout << '\n';
      }
      for(int j = 1; j <= n; j++){
          cout << arr[0][j] << " ";
      }
      return 0;

      }

