#include <bits/stdc++.h>
#define sz(s) int(s.size())
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    int color[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    fill(color + 1, color + 1 + n, 0);
    int k = n;
    while(k > (n / 2)){
        int x = rand() % n + 1;
        while(color[x] == 0){
            x = rand() % n + 1;
        }
        int kol = 0;
        for(int j = 1; j <= n; j++){
            if(arr[j] == arr[x]){
                color[j] = 1;
                kol++;
            }
        }
        if(kol >= n/2) {
            cout << "yes";
            return 0;
        }
        k -= kol;
    }
    cout << "no";
    return 0;
}
