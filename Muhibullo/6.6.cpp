# include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    
    int mx_sum, ans_i = -1, ans_j;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = i; j <= n; j++){
            sum += arr[j];
            if((ans_i == -1) || (sum > mx_sum)){
                mx_sum = sum;
                ans_i = i;
                ans_j = j;
            }
        }
    }
    
    cout << "i = " << ans_i << " j = " << ans_j;
    return 0;
}
