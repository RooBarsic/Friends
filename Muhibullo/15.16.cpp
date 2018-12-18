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
            int flag = 0;
            for(int x = 1; x <= k; x++){
                if(arr[id][x] > arr[j][x]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) id = j;
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
