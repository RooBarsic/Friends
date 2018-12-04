# include <iostream>

using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m;
    int arr[n + 2][ m + 2];
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            arr[i][j] = 0;
        }
        arr[i][0] = arr[i][m + 1] = -1;
    }
    for(int i = 1; i <= m; i++){
        arr[0][i] = arr[n + 1][i] = -1;
    }
    
    i = 1;
    j = 1;
    int k = 1;
    while(k <= n * m){
        while(arr[i][j] == 0){
            arr[i][j] = k;
            k++;
            j++;
        }
        j--;
        i++;
        while(arr[i][j] == 0){
            arr[i][j] = k;
            k++;
            i++;
        }
        i--;
        j--;
        while(arr[i][j] == 0){
            arr[i][j] = k;
            k++;
            j--;
        }
        j++;
        i--;
        while(arr[i][j] == 0){
            arr[i][j] = k;
            k++;
            i--;
        }
        i++;
        j++;
    }
    
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
