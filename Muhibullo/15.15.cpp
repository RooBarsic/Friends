# include <bits/stdc++.h>
  using namespace std;

  int main(){
    int n, m, k;
    cin >> n >> m >> k;
    long long arr[n + 1][m + 1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        int id = i;
        for(int j = i + 1; j <= n; j++){
            if(arr[id][k] > arr[j][k]) id = j;
        }
        if(id != i){
            for(int j = 1; j <= m; j++){
                swap(arr[i][j], arr[id][j]);
            }
        }
    }

    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
  }
