# include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> m;
    int krr[m + 1];
    for(int i = 1; i <= m; i++){
        cin >> krr[i];
    }
    
    cin >> n;
    int lrr[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> lrr[i];
    }
    
    int ans, ans_flag = 0;
    for(int i = 1; i <= m; i++){
        int flag = 0;
        for(int j = 1; j <= n; j++){
            if(krr[i] == lrr[j]) flag = 1;
        }
        if(flag == 0){
            if((ans_flag == 0) || (ans < krr[i])){
                ans = krr[i];
                ans_flag = 1;
            }
        }
    }
    
    if(ans_flag == 0) cout << "No answer";
    else cout << ans;
    
    return 0;
}
