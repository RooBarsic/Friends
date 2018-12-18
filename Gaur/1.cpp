# include <bits/stdc++.h>
  using namespace std;

  int main(){
    int n, m, k;
    cin >> k >> n;
    long long arr[k + 1][k + 1];
    long long result[k + 1][k + 1];
    long long prr[k + 1][k + 1];
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            cin >> arr[i][j];
            result[i][j] = 1ll;
            prr[i][j] = arr[i][j];
        }
    }
    cout << '\n';
    long long fact = 1ll;
    for(long long i = 1; i <= n; i++){
        fact = fact * i;

        for(int x = 1; x <= k; x++){
            for(int y = 1; y <= k; y++){
                result[x][y] += (prr[x][y] / fact);
            }
        }

        long long crr[k + 1][k + 1];
        for(int x = 1; x <= k; x++){
            for(int y = 1; y <= k; y++){
                crr[x][y] = 0;
                for(int j = 1; j <= k; j++){
                    crr[x][y] += arr[x][j] * prr[j][y];
                }
            }
        }

        for(int x = 1; x <= k; x++){
            for(int y = 1; y <= k; y++){
                prr[x][y] = crr[x][y];
            }
        }
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
  }
