#include<iostream>
#include<string>
#include <map>
#define sz(s) int(s.size())
 using namespace std;
 int krr[60];
 int mrr[60];
long long pi = 1000000007ll;
map<int, long long> dp[12];
 void lob(int n){
     int ans = 0;
     int m = 0;
     for(int i = 1; i <= n; i++){
         int y = i % 10;
         int x = i / 10;
         int flag = 1;
         while(x > 0){
             if(x % 10 > y){
                 flag = 0;
             }
             y = x % 10;
             x = x / 10;
         }
         ans += flag;
         if(flag == 0) {
             m++;
             cout << i << '\n';
         }
     }
     cout << " ans = " << ans  << " m = " << m << " ans + m  = " << ans + m << '\n';
 }
 long long geta(int x, int k, int b = 9){
     if((x < 0) || (k <= 0)) return 0;
     if(k == 1)
         return b - x + 1;
     long long ans = dp[x][k];
     if(ans > 0)
         return ans;
     long long kol = 1;
     for(int i = x; i <= b; i++){
         ans = (ans + kol * geta(i, k - 1)) % pi;
         kol++;
     }
     dp[x][k] = ans;
     return ans;
 }
 int main(){
     int n;
    string k, m;
    cin >> k >> m;
    while(sz(k) != sz(m)){
        if(sz(k) > sz(m)) m = "0" + m;
        else k = "0" + k;
    }
    n = sz(k);
    for(int i = 0; i < n; i++){
        krr[i + 1] = int(k[i]) - int('0');
        mrr[i + 1] = int(m[i]) - int('0');
    }
    int kmx = 0;
    int mmx = 0;
    int flag = 1;
    for(int i = 1; i <= n; i++){
        kmx = max(kmx, krr[i]);
        krr[i] = kmx;
        if(flag == 1){
            if(krr[i] > mrr[i]) {
                cout << 0;
                return 0;
            }
            if(krr[i] < mrr[i]){
                flag = 0;
            }
        }
        mmx = max(mmx, mrr[i]);
        mrr[i] = mmx;
    }

    long long ans = 1;
    for(int i = n; i >= 1; i--){
        if(krr[i] < mrr[i]){
            //cout << krr[i] << " " << mrr[i] << '\n';
            for(int j = i + 1; j <= n; j++){
                if(j != n) ans = (ans + geta(krr[j] + 1, n - j)) % pi;
                else {
                    ans = (ans + (9 - krr[j])) % pi;
                }
            }
            //cout << ans << '\n';
            for(int j = krr[i] + 1; j < mrr[i]; j++){
                ans = (ans + geta(j, n - i)) % pi;
            }
            //cout << ans << '\n';
            for(int j = i + 1; j <= n; j++){
                //cout << " dsfg " << mrr[j - 1] << " " << n - j + 1 << " " << mrr[j] << '\n';
                ans = (ans + geta(mrr[j - 1], n - j + 1, mrr[j])) % pi;
            }
            //cout << ans << '\n';
        }
    }
    cout << ans % pi;
    return 0;
 }
