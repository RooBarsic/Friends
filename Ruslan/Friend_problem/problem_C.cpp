# include<bits/stdc++.h>
# define sz(s) int(s.size())
using namespace std;
int prost = 500009;
int calc_hash(string s){
    if(sz(s) == 0) return 0;
    int hash = 0, i;
    for(int i = 0, len = sz(s); i < len; i++) {
        hash = (prost * hash) + int(s[i]);
    }
    return hash;
}
int arr[505000];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        arr[i] = calc_hash(s);
    }
    sort(arr + 1, arr + 1 + n);
    int ans = 1;
    for(int i = 2; i <= n; i++){
        if(arr[i - 1] != arr[i]) ans++;
    }
    cout << ans;
    return 0;
}
