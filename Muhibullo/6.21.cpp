# include <iostream>

using namespace std;

int main(){
    int m, n, sum;
    cin >> m >> n;
    int arr[m + 1][n + 1];
    int flag[m + 1][n + 1];
    sum = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            flag[i][j] = 1;
        }
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(flag[i][j] == 1){
                int kol = 0;
                for(int x = 1; x <= m; x++){
                    for(int y = 1; y <= n; y++){
                        if(arr[i][j] == arr[x][y]){
                            kol++;
                            break;
                        }
                    }
                    if(kol != x) break;
                }
                
                if(kol == m) {
                    cout << arr[i][j] << " ";
                    for(int x = 1; x <= m; x++){
                        for(int y = 1; y <= n; y++){
                            if(arr[i][j] == arr[x][y]) flag[x][y] = 0;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
