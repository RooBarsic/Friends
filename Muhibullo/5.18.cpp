# include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1][n + 1];
    
    for(int j = n; j >= 1; j--){
        for(int i = 1; i <= n; i++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
