# include <iostream>

using namespace std;

int main(){
    int m;
    cin >> m;
    int arr[m + 1][m + 1];
    
    for(int i = 1; i <= m; i++){
        arr[i][0] = arr[0][i] = 0;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            arr[i][0] += arr[i][j];
            arr[0][j] += arr[i][j];
        }
    }
    
    int ans_i = -1, ans_j = -1;
    for(int x = 1; x <= m; x++){
        if(arr[x][0] == 0) ans_i = x;
        if(arr[0][x] == 0) ans_j = x;
    }
    
    if(ans_i != -1) cout << " i = " << ans_i;
    else if(ans_j != -1) cout << " j = " << ans_j;
    else cout << "No answer";
    return 0;
}
